#ifndef STRING_H
#define STRING_H

#include <stddef.h> // for size_t

size_t strlen(const char* str);
void *memset(void *s, int c, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);
void *memcpy(void *restrict s1, const void *restrict s2, size_t n);

#endif
