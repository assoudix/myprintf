#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#define UNUSED(x) (void)(x)

/*struct to link funcs*/

typedef struct specifier {
    char spec;
    void (*func)(va_list args, int *count);
} specifier_t;

/*main function*/

int _printf(const char *format, ...);
int format_parser(const char* format, specifier_t specifiers[], va_list args);

/*output using the write syscall*/

void print_char(va_list arg, int *count);
void print_string(va_list arg, int *count);
void print_int(va_list arg, int* count);
void print_perc(va_list arg, int *count);

/*conversion functions*/

char* int_to_str(int num);

#endif
