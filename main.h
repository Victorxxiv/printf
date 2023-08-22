#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>  /* Required for variable arguments */
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

#endif /* MAIN_H */
