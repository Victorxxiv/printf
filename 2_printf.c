#include "main.h"
#include <stdarg.h>

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 * @...: Additional arguments for format placeholders.
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr;

	va_start(args, format);

	for (ptr = format; *ptr; ptr++)
	{
		if (*ptr != '%')
		{
			/* Print non-% characters */
			_putchar(*ptr);
			count++;
		}
		else
		{
			ptr++;
			if (*ptr == 'c')
			{
				/* Handle %c */
				char c = va_arg(args, int);

				_putchar(c);
				count++;
			}
			else if (*ptr == 's')
			{
				/* Handle %s */
				char *str = va_arg(args, char *);

				if
					(!str) str = "(null)";
				while (*str)
				{
					_putchar(*str);
					str++;
					count++;
				}
			}
			else if (*ptr == 'd' || *ptr == 'i')
			{
				/* Handle %d or %i */
				int num = va_arg(args, int);

				if (num < 0)
				{
					_putchar('-');
					count++;
					num = -num;
				}
				count += print_number(num);
			}
			else if (*ptr == 'b')
			{
				/* Handle %b */
				unsigned int num = va_arg(args, unsigned int);

				count += print_binary(num);
			}
			else if (*ptr == '%')
			{
				/* Handle %% */
				_putchar('%');
				count++;
			}
			else
			{
				/* Handle unknown specifier */
				_putchar('%');
				_putchar(*ptr);
				count += 2;
			}
		}
	}

	va_end(args);
	return (count);
}

