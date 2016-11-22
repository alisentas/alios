#include "string.h"
#include <stdint.h>

void *memset16(void *s, uint16_t c, size_t n){
    size_t i = 0;
    uint16_t *buf = (uint16_t*)s;
    for(;i < n; ++i){
        buf[i] = (uint16_t)c;
    }
    return s;
}
