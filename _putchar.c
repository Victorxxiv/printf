#include <unistd.h>  /* Required for the write function */

/**
 * _putchar - Writes a character to standard output
 * @c: The character to write
 * Return: On success, 1. On error, -1 and errno is set appropriately.
 */
int _putchar(char c)
{
	/* Use the write system call to output a single character */
	return (write(1, &c, 1));
}
