#include "main.h"

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

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr != '%')
		{
			_putchar(*ptr);
			count++;
		}
		else
		{
			ptr++;  /* Move past '%' character */
			if (*ptr == 'c')
			{
				/* Print a char argument */
				char c = va_arg(args, int); /* char gets promoted to int */

				_putchar(c);
				count++;
			}
			else if (*ptr == 's')
			{
				/* Print a string argument */
				char *str = va_arg(args, char *);

				if (str == NULL)
					str = "(null)";
				while (*str != '\0')
				{
					_putchar(*str);
					count++;
					str++;
				}
			}
			else if (*ptr == '%')
			{
				_putchar('%');
				count++;
			}
			else
			{
				/* Handle unsupported conversion specifier */
				_putchar('%');
				_putchar(*ptr);
				count += 2;
			}
		}
	}

	va_end(args);

	return (count);
}

