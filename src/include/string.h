#ifndef __SRC_INCLUDE_LIB_H__
#define __SRC_INCLUDE_LIB_H__

#include <stdarg.h>
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

void* memcpy(void* to, const void* from, size_t len);
void* memcpy_b(void* to, const void* from, size_t len);
void* memcpy_w(void* to, const void* from, size_t len);
void* memcpy_l(void* to, const void* from, size_t len);

int vsnprintf(char *buf, size_t size, const char *fmt, va_list args);
int snprintf( char *buf, size_t size, const char *fmt, ... ) __attribute__((format( printf, 3, 4 )));

int strlen( const char* str );

#ifdef __cplusplus
}
#endif

#endif //__SRC_INCLUDE_LIB_H__
