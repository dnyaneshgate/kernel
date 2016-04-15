
#include "string.h"

int snprintf( char* buf, size_t size, const char* format, ... ) {
    va_list ap;
    va_start( ap, format );
    int nbytes = vsnprintf( buf, size, format, ap );
    va_end( ap );
    return nbytes;
}

int strlen( const char* str ) {
    int length = 0;
    if( !str ) return 0;
    while( *str++ ) length++;
    return length;
}
