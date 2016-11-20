#include <stdarg.h> // for va_list
#include "stdio.h"
#include "math.h"

void print_num(int x){
    putchar('0'+x);
}

int printf(const char *restrict format, ...){
    va_list *ap;
    va_start(ap, format);

    //terminal_writestring(format);

    while(*format != '\0'){
        if(format[0] == '%'){
            if(format[1] == '%'){
                putchar('%');
                format += 2;
            }else if(format[1] == 'd'){ // print integer
                int i = va_arg(ap, int);
                int i_b = i;
                int i_c = 0;
                if(i < 0){
                    putchar('-');
                    i = 0 - i;
                    i_b = i;
                }
                while(i > 0){
                    ++i_c;
                    i /= 10;
                }
                --i_c;
                while(i_c >= 0){
                    putchar('0' + (i_b / pow(10, i_c)));
                    i_b -= (i_b / pow(10, i_c)) * pow(10, i_c);
                    --i_c;
                }
                format += 2;
            }else{
                printf("invalid format");
                format += 2;
            }
        }else{
            while(*format && *format != '%'){
                putchar(*format);
                ++format;
            }
        }
    }

    return 0;
}
