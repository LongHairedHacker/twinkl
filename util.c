#include <string.h>

#include "util.h"

void twinkl_memset(void *ptr, int value, size_t num) {
	memset(ptr, value, num);
}

void twinkl_memcpy(void *destination, const void *source, size_t num) {
	memcpy(destination, source, num);
}
