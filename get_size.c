#include "main.h"

/**
 * get_size - This function determines the appropriate size for casting or converting the argument.
 * Authored by Victor and Cindy.
 * @format: The formatted string used for printing the arguments.
 * @i: List of arguments intended for printing.
 *
 * Return: Precision value.
 */
int get_size(const char *format, int *i)
{
        int curr_i = *i + 1;
        int size = 0;

        if (format[curr_i] == 'l')
                size = S_LONG;
        else if (format[curr_i] == 'h')
                size = S_SHORT;

        if (size == 0)
                *i = curr_i - 1;
        else
                *i = curr_i;

        return (size);
}
