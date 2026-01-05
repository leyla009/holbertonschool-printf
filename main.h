#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct specifier
{
	char spec;
	int (*f)(va_list);
} spec_t;

int _putchar(char c);
int _printf(const char *format, ...);

/* Task 0 - 4 Functions */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);     /* Used for both %d and %i */
int print_binary(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex_low(va_list args);
int print_hex_upp(va_list args);

#endif
