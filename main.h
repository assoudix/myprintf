#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
* struct linker - a table linking subroutines to specifiers
*
* @specifier: The specifiers
* @f: The corresponding subroutine
*/
struct linker
{
	char *specifier;
	int (*f)(va_list);
};
typedef struct linker f_to_c;


/*_printf subroutines*/
int parser(const char *format, f_to_c functions[], va_list arguments);
int _printf(const char *format, ...);

/*prints a single character*/
int _putchar(char);

/*prints a number & converts it to str*/
int print_number(va_list);

/*printing linker functions*/
int print_char(va_list);
int print_string(va_list);
int print_percent(va_list);
int print_integer(va_list);


#endif
