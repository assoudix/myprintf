#include "main.h"

/**
 * _printf - Receives the main string and all the necessary parameters to
 * print a formated string
 * @format: A string containing all the desired characters
 * Return: A total count of the characters printed
 */
int _printf(const char *format, ...)
{
	int count;
	f_to_c functions[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{NULL, NULL}
	};
	va_list arguments;

	if (format == NULL)
		return (-1);

	va_start(arguments, format);
	

	count = parser(format, functions, arguments);
	va_end(arguments);
	return (count);
}
