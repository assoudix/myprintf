#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - standard formatted output (behaves like printf from stdio)
 *
 * @format: the string to be printed containing specifiers
 * @... : arguments to be printed
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int count = 0;

	specifier_t specifiers[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_int},
		{'i', print_int},
	};

	va_list args;

	va_start(args, format);
	count = format_parser(format, specifiers, args);
	va_end(args);
	return (count);
}
