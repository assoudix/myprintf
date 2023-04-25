#include "main.h"

/**
 * _printf - mimics printf from stdio
 * so far it supports the following specifiers:
 * c, s, %, d, and i
 * coded by Omar Assoudi and Omar El Ouali
 * Special thanks to my dear friend and colleague :)
 *
 * @format: A string containing all the characters and specifiers
 * Return: number of printed characters
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
