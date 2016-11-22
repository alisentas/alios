#include "kernel.h"
#include <stdarg.h>
#include "stdio.h"

void panic(const char *restrict format, ...){
    va_list ap;
    int written = 0;

    printf("KERNEL PANIC! : ");

    va_start(ap, format);
    written = vprintf(format, ap);
    va_end(ap);

    while(1){}
}
