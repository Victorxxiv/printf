#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>

/* Custom _printf function */
int _printf(const char *format, ...);

/* Custom _putchar function */
int _putchar(char c);
int _strlen(char *s);
int print_number(int num);
int print_binary(unsigned int num);

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS. */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Format structure
 * Created by Victor and Cindy.
 *
 * @fmt: The format specifier.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Format structure
 *
 * @fmt: The format specifier.
 * @fn: The associated function.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list list, char buffer[],
		int flags, int width, int precision, int size);

/****************** PRINT FUNCTIONS ******************/

/* Functions to print characters and strings */
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size);
/* ... (other number printing functions) */

/* Function used to print non-printable characters */
int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* Function used to print memory addresses */
int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* Functions used to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/* Function used to print strings in reverse */
int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* Function used to print a string in ROT13 format */
int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* Width handler - handles width-related operations */
/* ... (width-related functions) */

/****************** UTILITIES ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
