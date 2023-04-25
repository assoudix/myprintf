#include "main.h"

/**
 * _putchar - Holberton's putchar, they love to complicate things :)
 *
 * @c: The character to print
 *
 * Return: Mimics the write syscall
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
