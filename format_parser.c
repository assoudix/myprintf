#include "main.h"

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>


/*
format_parser: analyzes format string and retrieves specifiers.
* prints corresponding args.
*
* @format: (str) string with specifiers
* specifiers: (specifier_t) a structure that maps the specifiers to functions
* that can print them except '%'
* @args: (va_list) list of arguments
* 
* Return: number of characters printed
*/

int format_parser(const char* format, specifier_t specifiers[], va_list args)
{
    int count =0, i=0;

while (*format != '\0') {
    if (*format == '%') {
        format++;
        {
        for (i = 0; specifiers[i].spec != '\0'; i++) {
            if (specifiers[i].spec == *format) {
                specifiers[i].func(args, &count);
                break;
            }
        }
        }
    } else {
        write(1, format, 1);
        count++;
    }
    format++;
}
    return count;
}
