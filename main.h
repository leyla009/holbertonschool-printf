#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

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

/* Main functions */
int _printf(const char *format, ...);
int _putchar(char c);

/* Task 0 - 3 functions */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_binary(va_list args);
int recursive_int(unsigned int num);

/* Task 4 functions (Unsigned, Octal, Hex) */
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex_low(va_list args);
int print_hex_upp(va_list args);

/* New helper for Task 5 */
void flush_buffer(char *buffer, int *buff_ind);

#endif
