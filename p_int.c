#include "main.h"

/**
 * print_number - prints a number send to this function
 * @args: List of arguments
 * Return: The number of arguments printed
 */
int print_number(va_list args)
{
    int n = va_arg(args, int);
    int len = 0;

    if (n < 0) {
        _putchar('-');
        n = -n;
        len++;
    }

    if (n / 10)
        len += print_number_helper(n / 10);

    _putchar(n % 10 + '0');
    len++;

    return len;
}

int print_number_helper(int n)
{
    int len = 0;

    if (n / 10)
        len += print_number_helper(n / 10);

    _putchar(n % 10 + '0');
    len++;

    return len;
}
