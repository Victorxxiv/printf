#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the
 * null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++; /* Move past '%' */

			if (*format == 'c') /* Character specifier */
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				count++;
			}
			else if (*format == 's') /* String specifier */
			{
				char *s = va_arg(args, char *);

				if (s)
				{
					while (*s)
					{
						write(1, s, 1);
						s++;
						count++;
					}
				}
			}
			else if (*format == '%') /* Percent specifier */
			{
				write(1, "%", 1);
				count++;
			}
			else
			{
				/* Unknown specifier, ignore */
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}

		format++;
	}

	va_end(args);

	return (count);
}

