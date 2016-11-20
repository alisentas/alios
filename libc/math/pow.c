#include "math.h"

int pow(int x, int y){
    if(y == 0){
        return 1;
    }
    int x_p = x;
    while(y > 1){
        x_p *= x;
        --y;
    }
    return x_p;
}
