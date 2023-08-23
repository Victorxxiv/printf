#include "main.h"

/**
 * print_int - Prints a signed integer
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int num = va_arg(types, int);
	int is_negative = 0;
	int i = BUFF_SIZE - 2;

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}

	buffer[BUFF_SIZE - 1] = '\0';

	if (num == 0)
		buffer[i--] = '0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
