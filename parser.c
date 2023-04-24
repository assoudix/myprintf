#include "main.h"

/**
 * parser - Receives the main string and all the necessary parameters to
 * print a formated string.
 * @format: A string containing all the desired characters.
 * @f_list: A list of all the posible functions.
 * @arg_list: A list containing all the argumentents passed to the program.
 * Return: A total count of the characters printed.
 */
int parser(const char *format, f_to_c functions[], va_list arguments)
{
	int i, j, print_counter, counter;

	counter = 0;
	for (i=0; format[i] != '\0'; i++)
	{
		if (format[i] == '%') 
		{
			
			for (j=0; functions[j].specifier != NULL; j++)
			{
				if (format[i + 1] == functions[j].specifier[0])
				{
					print_counter = functions[j].f(arguments);
					if (print_counter == -1)
						return (-1);
					counter += print_counter;
					break;
				}
			}
			if (functions[j].specifier == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					counter++;
					_putchar(format[i + 1]);
					counter++;
				}
				else
					return (-1);
			}
			i++; 
		}
		else
		{
			_putchar(format[i]); 
			counter++;
		}
	}
	return (counter);
}
