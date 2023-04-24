#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
* struct convert - defines a structure for symbols and functions
*
* @sym: The operator
* @f: The function associated
*/
struct linker
{
	char *specifier;
	int (*f)(va_list);
};
typedef struct linker f_to_c;

/*Main functions*/
int parser(const char *format, f_to_c functions[], va_list arguments);
int _printf(const char *format, ...);
int _putchar(char);
int print_char(va_list);
int print_string(va_list);
int print_percent(va_list);
int print_integer(va_list);
int print_number(va_list);
int print_number_helper(int n);

#endif
