

#include <stdarg.h>
#include "kernel/console.hpp"
#include "kernel/arch/x86/port.hpp"
#include "string.h"
#include "types.h"

#define MAX_SCREEN_WIDTH 80
#define MAX_SCREEN_HEIGHT 25

#define CONSOLE_MAKE_COLOR( fg, bg ) ( (fg) | (bg<<4) )
#define CONSOLE_MAKE_CHAR( c, color ) ( (c) | ( color << 8 ) )

namespace io {
namespace console {
    
static unsigned char fg_color = COLOR_LIGHT_GREY;
static unsigned char bg_color = COLOR_BLACK;

static unsigned short* _video_buffer = (unsigned short*) 0xB8000;
static unsigned char _screen_x=0, _screen_y=0;
//static unsigned char _screen_color = CONSOLE_MAKE_COLOR( fg_color, bg_color );

static void move_cursor() {
    unsigned short i = _screen_x + ( _screen_y * MAX_SCREEN_WIDTH );
    io::port::WriteByte( 0x3D4, 14 );
    io::port::WriteByte( 0x3D5, i >> 8 );
    io::port::WriteByte( 0x3D4, 15 );
    io::port::WriteByte( 0x3D5, i );
}

void clear() {
    unsigned char color = CONSOLE_MAKE_COLOR( bg_color, bg_color );
    int i=0, end = MAX_SCREEN_WIDTH * MAX_SCREEN_HEIGHT;
    while( i < end ) {
        _video_buffer[i++] = CONSOLE_MAKE_CHAR( ' ', color );
    }
    _screen_x = _screen_y = 0;
    move_cursor();
}

void scroll_up() {
    for( int i=1; i<MAX_SCREEN_HEIGHT; i++ ) {
        memcpy_w( &_video_buffer[ (i-1) * MAX_SCREEN_WIDTH ],
                &_video_buffer[ (i) * MAX_SCREEN_WIDTH ],
                MAX_SCREEN_WIDTH );
    }
    for( int i=((MAX_SCREEN_HEIGHT-1)*(MAX_SCREEN_WIDTH)); i<(MAX_SCREEN_WIDTH*MAX_SCREEN_HEIGHT); i++ )
        _video_buffer[i] = CONSOLE_MAKE_CHAR( ' ', CONSOLE_MAKE_COLOR( bg_color, bg_color ) );
}

void printf( const char* format, ... ) {
    char buffer[4096];
    va_list ap;
    va_start( ap, format );
    vsnprintf( buffer, sizeof(buffer), format, ap );
    va_end( ap );
    print( buffer );
}

void print( const char* string ) {
    unsigned char color = CONSOLE_MAKE_COLOR( fg_color, bg_color );
    while( *string != '\0' ) {
        switch( *string ) {
            case '\n': {
                _screen_x = 0;
                ++_screen_y;
            }
            break;
            
            case '\t': {
                _screen_x += 4;
            }
            break;
            
            default: {
                int index = _screen_x + ( _screen_y * MAX_SCREEN_WIDTH );
                _video_buffer[index] = CONSOLE_MAKE_CHAR( *string, color );
                ++_screen_x;
                if( _screen_x >= MAX_SCREEN_WIDTH ) {
                    _screen_x = 0;
                    ++_screen_y;
                }
            }
        }
        
        if( _screen_y >= MAX_SCREEN_HEIGHT ) {
            scroll_up();
            _screen_x = 0;
            --_screen_y;
        }
        
        move_cursor();
        
        string++;
    }
}

} /* namespace console */
} /* namespace io */
