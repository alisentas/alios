#include "string.h"

void *memset(void *s, int c, size_t n){
    size_t i = 0;
    unsigned char *buf = (unsigned char*)s;
    for(;i < n; ++i){
        buf[i] = (unsigned char)c;
    }
    return s;
}
