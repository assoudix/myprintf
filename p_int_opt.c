#include <stdarg.h>
#include "main.h"

/**
 * print_number - prints a using recursion
 * @args: List of arguments
 * Return: The number of arguments printed
 */

int print_number(va_list args) {
    int n = va_arg(args, int);
    int len = 0;
    if (n < 0) {
        putchar('-');
        n = -n;
        len++;
    }
    if (n / 10)
        len += print_number(n / 10);
    putchar(n % 10 + '0');
    len++;
    return len;
}
