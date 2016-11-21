#include "string.h"

void *memcpy(void *restrict s1, const void *restrict s2, size_t n){
    size_t i = 0;
    unsigned char *uc_s1 = (unsigned char*)s1;
    const unsigned char* uc_s2 = (const unsigned char*)s2;
    for(; i < n; ++i)
        uc_s1[i] = uc_s2[i];
    return s1;
}
