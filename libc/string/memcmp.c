#include <stdbool.h>
#include "string.h"

int memcmp(const void *s1, const void *s2, size_t n){
    size_t i = 0;
    unsigned char *uc_s1 = (unsigned char*)s1;
    unsigned char *uc_s2 = (unsigned char*)s2;
    for(; i < n; ++i){
        if(uc_s1[i] < uc_s2[i])
            return -1;
        else if(uc_s1[i] > uc_s2[i])
            return 1;
    }
    return 0;
}
