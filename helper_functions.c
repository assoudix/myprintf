#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_char - prints a single character to stdout
 *
 * @arg: the character to be printed
 * @count: total print count
 *
 * Return: Nothing
 */

void print_char(va_list arg, int *count)
{
	char c = va_arg(arg, int);

	write(1, &c, 1);
	(*count)++;
}

/**
 * print_string - prints a string to stdout
 * when specifier %s is used
 *
 * @arg: the string to be printed
 * @count: total print count
 *
 * Return: Nothing
 */

void print_string(va_list arg, int *count)
{
	char *str = va_arg(arg, char *);

	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
		(*count)++;
	}
}


/**
 * print_int - prints an integer to stdout
 *
 * @arg: the integer to be printed
 * @count: total print count
 *
 * Return: Nothing
 */

void print_int(va_list arg, int *count)
{
	int num = va_arg(arg, int);

	char *str = int_to_str(num);

	char *ptr = str; /* Keep a copy of the original pointer to free it */

	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
		(*count)++;
	}
	free(ptr);
}



/**
 * int_to_str - converts int to str
 * @num: integer to be converted
 *
 * Return: the integer in string format
 *
 */

char *int_to_str(int num)
{
	char *str = (char *) malloc(32 * sizeof(char));

	int j, i = 0;

	int is_negative = 0;


	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}


	do {
		str[i++] = num % 10 + '0';
		num /= 10;
	} while (num != 0);


	if (is_negative)
		str[i++] = '-';


	for (j = 0; j < i / 2; j++)
	{
		char temp = str[j];

		str[j] = str[i - j - 1];
		str[i - j - 1] = temp;
	}


	str[i] = '\0';

	return (str);
}
