#ifndef STDIO_H
#define STDIO_H

#include <stdarg.h> // for va_list

int printf(const char *format, ...);
int putchar(int c);
int puts(const char *str);
int vprintf(const char *restrict format, va_list ap);

#endif
