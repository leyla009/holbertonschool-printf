#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct specifier - Struct for specifiers
 * @spec: The character (c, s, d, i, b, u, o, x, X)
 * @f: The function pointer associated
 */
typedef struct specifier
{
	char spec;
	int (*f)(va_list);
} spec_t;

int _printf(const char *format, ...);
int _putchar(char c);

/* Task 0-2 */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);

/* Task 3-4 */
int print_binary(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex_low(va_list args);
int print_hex_upp(va_list args);

#endif
