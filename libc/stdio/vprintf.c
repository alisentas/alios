#include <stdarg.h> // for va_list
#include "stdio.h"
#include "math.h"

int vprintf(const char *restrict format, va_list ap){
    int written = 0;

    while(*format != '\0'){
        if(format[0] == '%'){
            if(format[1] == '%'){
                putchar('%');
                format += 2;
                ++written;
            }else if(format[1] == 'd'){ // print integer
                int i = va_arg(ap, int);
                if(i == 0){
                    putchar('0');
                    ++written;
                    format += 2;
                    continue;
                }
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
                    putchar('0' + (i_b / (int)pow(10, i_c)));
                    i_b -= (i_b / (int)pow(10, i_c)) * (int)pow(10, i_c);
                    --i_c;
                }
                format += 2;
            }else if(format[1] == 'c'){ // print char
                putchar(va_arg(ap, int)); // char promotes to int
                format += 2;
                ++written;
            }else if(format[1] == 's'){ // print string
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

    return written;
}
