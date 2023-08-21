#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 * @...: Variable number of arguments.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;   /* Declare a variable to hold the arguments */
	int count = 0;  /* Initialize the character count */
	char *str_arg;  /* Declare a variable to hold string arguments */

	va_start(args, format); /* Initialize the argument list */

	while (*format)
	{
		if (*format == '%') /* Check for the start of a conversion specifier */
		{
			format++; /* Move past '%' */
			switch (*format)
			{
				case 'c':
					/* Handle character argument */
					count += write(1, &va_arg(args, int), 1);
					break;
				case 's':
					/* Handle string argument */
					str_arg = va_arg(args, char *);
					if (str_arg)
						count += write(1, str_arg, strlen(str_arg));
					else
						count += write(1, "(null)", 6);
					break;
				case '%':
					/* Handle '%' character */
					count += write(1, "%", 1);
					break;
				default:
					/* Handle unknown conversion specifiers */
					count += write(1, "%", 1);
					count += write(1, &(*format), 1);
					break;
			}
		}
		else
		{
			/* Regular character, print as is */
			count += write(1, format, 1);
		}
		format++; /* Move to the next character in format */
	}

	va_end(args); /* Clean up the argument list */

	return (count);
}

