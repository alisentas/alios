#include "math.h"

double pow(double x, double y){
    if(y == 0){
        return 1;
    }
    double x_p = x;
    while(y > 1){
        x_p *= x;
        --y;
    }
    return x_p;
}
