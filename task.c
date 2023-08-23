#include "main.h"

/**
 * int_to_str - Convert an integer to a string representation.
 * @num: The integer to convert.
 * @buffer: The buffer to store the resulting string.
 *
 * Return: The length of the generated string.
 */
int int_to_str(int num, char *buffer)
{
	int length = 0;
	int temp = num;

	/* Calculate the number of digits in the integer */
	while (temp != 0)
	{
		temp /= 10;
		length++;
	}

	buffer[length] = '\0'; /* Null-terminate the string */

	/* Convert each digit to character and store in buffer */
	for (int i = length - 1; i >= 0; i--)
	{
		buffer[i] = '0' + (num % 10);
		num /= 10;
	}

	return (length);
}

/**
 * _printf - Custom printf function for Task 0.
 * @format: Format string.
 * @...: Variable arguments list.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr = format;

	if (!format)
		return (-1);

	va_start(args, format);

	while (*ptr)
	{
		if (*ptr == '%' && *(ptr + 1) != '\0')
		{
			if (*(ptr + 1) == 'd' || *(ptr + 1) == 'i')
			{
				/* Handle %d and %i conversion specifiers */
				int num = va_arg(args, int);
				char buffer[20]; /* Assuming max 20 digits for an integer */

				int length = int_to_str(num, buffer);

				write(1, buffer, length);
				count += length;

				ptr += 2;
				continue;
			}
		}
		write(1, ptr, 1);
		count++;
		ptr++;
	}

	va_end(args);

	return (count);
}

