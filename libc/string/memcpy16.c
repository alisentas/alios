#include "string.h"
#include <stdint.h>

/* this function copies arrays, longer than const char */
/* this is not in c standard, my humble implementation */
/* only needed in terminal_scroll function for now */
void *memcpy16(void *restrict s1, const void *restrict s2, size_t n){
    size_t i = 0;
    uint16_t *uc_s1 = (uint16_t*)s1;
    const uint16_t* uc_s2 = (const uint16_t*)s2;
    for(; i < n; ++i)
        uc_s1[i] = uc_s2[i];
    return s1;
}
