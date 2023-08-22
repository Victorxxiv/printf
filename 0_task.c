#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * Returns the length of a string
 */

int _strlen(char *s)
{
	int i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

/**
 * @param c, the character to be printed
 * Writes a single character to the standard output (stdout)
 */
void _putchar(char c)
{
	write(1, &c, 1);
}

/**
 * @param format, a character string composed of zero or more directives
 * @endpoints..., the optional arguments
 * Reproduces the printf function
 */

int _printf(const char *format, ...)
{
	/* The total number of characters written */
	/* It will be returned at the end of `_printf` */
	int total_char = 0;

	/* Declaring the list of arguments */
	va_list args;

	/* Initializing 'args' to store all values after 'format' */
	va_start(args, format);

	/* Traverse through the list to find valid identifiers */
	for (; *format != '\0'; format++)
	{
		while (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					{
						char c = va_arg(args, int);

						_putchar(c);
						total_char++;
						format++;
					}
					break;

				case 's':
					{
						char *s = va_arg(args, char*);
						int len = _strlen(s);
						write(1, s, len);
						total_char += len;
						format++;
					}
					break;

				case '%':
					{
						_putchar('%');
						total_char++;
						format++;
					}
					break;
			}
		}

		/* For characters that are not preceded by '%' */
		if (*format != '\0')
		{
			_putchar(*format);
			total_char++;
		}
	}

	/* Cleaning up the list */
	va_end(args);

	/* Returning the number of characters printed */
	return (total_char);
}

