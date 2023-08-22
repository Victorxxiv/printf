#include "main.h"

/**
 * print_number - Prints an integer as a sequence of digits.
 * @num: The integer to print.
 * Return: The number of characters printed.
 */
int print_number(int num)
{
	int count = 0;

	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}

	count += recursive_print(num);
	return (count);
}

/**
 * print_binary - Prints an unsigned integer as a binary number.
 * @num: The unsigned integer to print as binary.
 * Return: The number of characters printed.
 */
int print_binary(unsigned int num)
{
	int count = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	count += recursive_binary(num);
	return (count);
}

/**
 * recursive_print - Recursively prints digits of a number.
 * @num: The number to print digits of.
 * Return: The number of characters printed.
 */
int recursive_print(int num)
{
	int count = 0;

	if (num / 10 != 0)
		count += recursive_print(num / 10);

	_putchar('0' + num % 10);
	return (count + 1);
}

/**
 * recursive_binary - Recursively prints binary representation of a number.
 * @num: The number to print in binary.
 * Return: The number of characters printed.
 */
int recursive_binary(unsigned int num)
{
	int count = 0;

	if (num / 2 != 0)
		count += recursive_binary(num / 2);

	_putchar('0' + num % 2);
	return (count + 1);
}

