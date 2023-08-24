#include "main.h"

/**
 * is_printable - Determines if a character is printable or not.
 *  Created by Cindy and Victor.
 * @c: Character to be checked
 *
 * Return: 1 if Char c is printable, otherwise returns 0.
 */
int is_printable(char c)
{
        if (c >= 32 && c < 127)
                return (1);

        return (0);
}

/**
 * append_hexa_code - Appends the ASCII value in hexadecimal code to the buffer.
 * @buffer: Array of characters to append to.
 * @i: Index in the buffer where the appending starts.
 * @ascii_code: ASCII code to be converted.
 * Return: Always returns 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
        char map_to[] = "0123456789ABCDEF";

        if (ascii_code < 0)
                ascii_code *= -1;

        buffer[i++] = '\\';
        buffer[i++] = 'x';

        buffer[i++] = map_to[ascii_code / 16];
        buffer[i] = map_to[ascii_code % 16];

        return (3);
}

/**
 * is_digit - Checks if a character is a digit.
 * @c: Character to be checked.
 *
 * Return: 1 if c is a digit, otherwise returns 0.
 */
int is_digit(char c)
{
        if (c >= '0' && c <= '9')
                return (1);

        return (0);
}

/**
 * convert_size_number - Converts a number to the specified size.
 * @num: Number to be converted.
 * @size: The size indicating the desired type of conversion.
 *
 * Return: The converted value of the number num
 */
long int convert_size_number(long int num, int size)
{
        if (size == S_LONG)
                return (num);
        else if (size == S_SHORT)
                return ((short)num);

        return ((int)num);
}

/**
 * convert_size_unsgnd - Converts an unsigned number to the specified size.
 * @num: Number to be converted
 * @size: The size indicating the desired type of conversion.
 *
 * Return: The converted value of the number num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
        if (size == S_LONG)
                return (num);
        else if (size == S_SHORT)
                return ((unsigned short)num);

        return ((unsigned int)num);
}
