#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

/**
 * struct specifier - Defines a format specifier for _printf.
 *
 * @spec: The format specifier character (e.g. 'd', 's', etc.)
 * @func: The function that handles this format specifier.
 */

typedef struct specifier
{
	char spec;
	void (*func)(va_list args, int *count);
}
specifier_t;

/*main function*/

int _printf(const char *format, ...);
int format_parser(const char *format, specifier_t specifiers[], va_list args);

/*output using the write syscall*/

void print_char(va_list arg, int *count);
void print_string(va_list arg, int *count);
void print_int(va_list arg, int *count);


/*conversion functions*/

char *int_to_str(int num);

#endif
