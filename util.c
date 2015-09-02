#include <string.h>

#include "util.h"

void* twinkl_memset(void *ptr, int value, size_t num) {
	return memset(ptr, value, num);
}

void* twinkl_memcpy(void *destination, const void *source, size_t num) {
	return memcpy(destination, source, num);
}
