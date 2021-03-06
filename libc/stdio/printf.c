#include <stdarg.h> // for va_list
#include "stdio.h"
#include "math.h"

int printf(const char *restrict format, ...){
    va_list ap;
    int written = 0;

    va_start(ap, format);
    written = vprintf(format, ap);
    va_end(ap);

    return written;
}
