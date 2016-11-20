#include <stdarg.h> // for va_list
#include "stdio.h"
#include "math.h"

void print_num(int x){
    putchar('0'+x);
}

int printf(const char *restrict format, ...){
    va_list *ap;
    va_start(ap, format);
    int written = 0;

    //terminal_writestring(format);

    while(*format != '\0'){
        if(format[0] == '%'){
            if(format[1] == '%'){
                putchar('%');
                format += 2;
                ++written;
            }else if(format[1] == 'd'){ // print integer
                int i = va_arg(ap, int);
                int i_b = i;
                int i_c = 0;
                if(i < 0){
                    putchar('-');
                    ++written;
                    i = 0 - i;
                    i_b = i;
                }
                while(i > 0){
                    ++i_c;
                    i /= 10;
                }
                written += i_c;
                --i_c;
                while(i_c >= 0){
                    putchar('0' + (i_b / pow(10, i_c)));
                    i_b -= (i_b / pow(10, i_c)) * pow(10, i_c);
                    --i_c;
                }
                format += 2;
            }else if(format[1] == 'c'){
                putchar(va_arg(ap, int)); // char promotes to int
                format += 2;
                ++written;
            }else if(format[1] == 's'){
                written += puts(va_arg(ap, const char*)) - 1;
                format += 2;
            }else{
                printf("invalid format");
                format += 2;
                written += 14;
            }
        }else{
            while(*format && *format != '%'){
                putchar(*format);
                ++format;
                ++written;
            }
        }
    }

    va_end(ap);

    return written;
}
