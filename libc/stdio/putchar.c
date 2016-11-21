#include "stdio.h"
#include "tty.h"

int putchar(int c){
    terminal_putchar((unsigned char)c);
    return c;
}
