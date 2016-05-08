
#include "string.h"

void memset( void* dest, char c, size_t size ) {
    asm volatile( "cld;\n"
                  "rep stosb;\n" : : "a"(c), "D"(dest), "c"(size) : "flags", "memory" );
}

void memset_w( void* dest, short c, size_t size ) {
    asm volatile( "cld;\n"
                  "rep stosw;\n" : : "a"(c), "D"(dest), "c"(size) : "flags", "memory" );
}

void memset_l( void* dest, int c, size_t size ) {
    asm volatile( "cld;\n"
                  "rep stosl;\n" : : "a"(c), "D"(dest), "c"(size) : "flags", "memory" );
}