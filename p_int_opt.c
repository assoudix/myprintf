#include "main.h"

/**
 * print_number - prints a number in base 10
 * uses va_list as input
 * @args: List of arguments
 * Return: length of the number
 */
int print_number(va_list args)
{
	int n;
	int divider;
	int length;
	unsigned int num;

	n  = va_arg(args, int);
	divider = 1;
	length = 0;

	if (n < 0)
	{
		length += _putchar('-');
		num = n * -1;
	}
	else
		num = n;

	while (num / divider > 9)
		divider *= 10;

	while (divider != 0)
	{
		length += _putchar('0' + num / divider);
		num %= divider;
		divider /= 10;
	}

	return (length);
}
