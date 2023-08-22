#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf produces output according to a format
 * @format- the format string
 * @...:Variable arguments corresponding to format specifiers
 * return:Number of characters printed
 */
int _printf(const char *format, ...)
{
	int printed_char = 0; /*counter for the number of chars printed*/
		va_list args; /*variable argument list*/

	va_start(args, format); /*initialize the variable argument list*/

	while (*format)
	{
		if (*format == '%') /*check for the start of a format specifier*/
		{
		format++; /*move to the char after '%'*/
		if (*format == '\0')
		{
			break; /*break if there is nothing after '%'*/

		}
		if (*format == 'c') /*handle character format specifier*/
		{
			char c = va_arg(args, int); /*get character argument*/

			_putchar(c); /*print the char*/
			printed_char++;
		}
		else if (*format == 's') /*handle string format specifier*/
		{
			char *s = va_arg(args, char*); /*get string argument*/

			while (*s) /*loop through the string*/
			{
				_putchar(*s); /*print each char*/
				s++;
				printed_char++;
			}
			else if (*format == '%') /*handle literal '%'*/
			{
				_putchar('%'); /*print '%' char*/
				printed_char++;
			{
				else /*handle invalid format specifier*/
			{
				_putchar('%'); /*print '%'*/
				_putchar(*format); /*print the inalid char*/
				printed_char += 2;
			}
		}
		else
		{
		_putchar(*format); /*print regular chars*/
			printed_char++;
		}
		format++;
		}

		va_end(args); /*end using variable argument list*/
return (printed_chars); /*return the total chars printed*/
	}
