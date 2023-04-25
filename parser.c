#include "main.h"

/**
 * parser - Receives the main string and all the necessary parameters to
 * print a formated string.
 * @format: input string
 * @functions: table linking subroutines to specifiers
 * @arguments: list of variadic arguments
 * Return: count of the characters printed.
 */
int parser(const char *format, f_to_c functions[], va_list arguments)
{
	int iterfor, iterfunc, print_counter, counter;

	counter = 0;
	for (iterfor = 0; format[iterfor] != '\0'; iterfor++)
	{
		if (format[iterfor] == '%')
		{
			for (iterfunc = 0; functions[iterfunc].specifier != NULL; iterfunc++)
			{
				if (format[iterfor + 1] == functions[iterfunc].specifier[0])
				{
					print_counter = functions[iterfunc].f(arguments);
					if (print_counter == -1)
						return (-1);
					counter += print_counter;
					break;
				}
			}
			if (functions[iterfunc].specifier == NULL && format[iterfor + 1] != ' ')
			{
				if (format[iterfor + 1] != '\0')
				{
					_putchar(format[iterfor]);
					counter++;
					_putchar(format[iterfor + 1]);
					counter++;
				}
				else
					return (-1);
			}
			iterfor++;
		}
		else
		{
			_putchar(format[iterfor]);
			counter++;
		}
	}
	return (counter);
}
