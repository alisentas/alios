#include "stdio.h"

int puts(const char *str){
    int retval = 1;
    while(*str != '\0'){
        putchar(*str);
        ++retval;
        ++str;
    }
    return retval;
}
