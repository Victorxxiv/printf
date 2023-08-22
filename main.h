#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>  /* Required for variable arguments */

/* Custom _printf function */
int _printf(const char *format, ...);

/* Custom _putchar function */
int _putchar(char c);
int print_number(int num);
int print_binary(unsigned int num);

#endif /* MAIN_H */
