
#ifndef __SRC_INCLUDE_KERNEL_CONSOLE_H__
#define __SRC_INCLUDE_KERNEL_CONSOLE_H__

enum {
    COLOR_BLACK = 0,
    COLOR_BLUE = 1,
    COLOR_GREEN = 2,
    COLOR_CYAN = 3,
    COLOR_RED = 4,
    COLOR_MAGENTA = 5,
    COLOR_BROWN = 6,
    COLOR_LIGHT_GREY = 7,
    COLOR_DARK_GREY = 8,
    COLOR_LIGHT_BLUE = 9,
    COLOR_LIGHT_GREEN = 10,
    COLOR_LIGHT_CYAN = 11,
    COLOR_LIGHT_RED = 12,
    COLOR_LIGHT_MAGENTA = 13,
    COLOR_LIGHT_BROWN = 14,
    COLOR_WHITE = 15,
};

void console_init();
void console_clear();
void console_print( const char* string );
void console_printf( const char* format, ... ) __attribute__((format( printf, 1, 2 )));

#endif //__SRC_INCLUDE_KERNEL_CONSOLE_H__
