#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdlib.h>

void* __attribute__((weak)) twinkl_memset(void *ptr, int value, size_t num);
void* __attribute__((weak)) twinkl_memcpy(void * destination, const void * source, size_t num);

#endif
