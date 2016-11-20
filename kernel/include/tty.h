#ifndef TTY_H
#define _TTY_H

#include <stddef.h> // for size_t
#include <stdint.h>

size_t strlen(const char* str);
void terminal_initialize(void);
void terminal_setcolor(uint8_t color);
void terminal_putentryat(unsigned char c, uint8_t color, size_t x, size_t y);
void terminal_putchar(unsigned char c);
void terminal_write(const char* data, size_t size);
void terminal_writestring(const char* data);

#endif
