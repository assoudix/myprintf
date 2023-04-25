#include "main.h"

/**
 * print_char - Prints a single character but uses va_list as input
 * @list: list of arguments
 * Return: 1
 */
int print_char(va_list list)
{
	_putchar(va_arg(list, int));
	return (1);
}

/**
 * print_string - Prints a string but uses va_list as input
 * @list: list of arguments
 * Return: # of printed characters
 */
int print_string(va_list list)
{
	int i;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * print_percent - Prints a percent symbol
 * @list: list of arguments (UNUSED)
 * Return: 1
 */
int print_percent(__attribute__((unused))va_list list)
{
	_putchar('%');
	return (1);
}

/**
 * print_integer - Prints an integer but uses va_list as input
 * @list: list of arguments
 * Return: length of the integer
 */
int print_integer(va_list list)
{
	int num_length;

	num_length = print_number(list);
	return (num_length);
}
