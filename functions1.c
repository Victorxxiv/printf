#include "main.h"

/****************** PRINTS AN UNSIGNED NUMBER. *************************/
/**
 * print_unsigned - This function prints an unsigned number.
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width specifier
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed.
 */
int print_unsigned(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINTS AN UNSIGNED NUMBER IN OCTAL NOTATION ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width specifier
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_octal(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** PRINTS UNSIGNED NUMBER IN HEXADECIMAL NOTATION. **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width specifier
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hexadecimal(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(args, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}

/******** PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL NOTATION. **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width specifier
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hexa_upper(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(args, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/********** PRINT HEXADECIMAL NUMBER IN LOWER OR UPPER CASE. **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or uppercase.
 * @args: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @flag_ch: Flag character
 * @width: Width specifier
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hexa(va_list args, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

