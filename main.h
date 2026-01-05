#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct specifier - Struct for specifiers
 * @spec: The character specifier
 * @f: The function pointer associated
 */
typedef struct specifier
{
	char spec;
	int (*f)(va_list, int, int);
} spec_t;

/* Core Functions */
int _putchar(char c);
int _printf(const char *format, ...);

/* Specifier Functions (All with flags and length) */
int print_char(va_list args, int flags, int length);
int print_string(va_list args, int flags, int length);
int print_percent(va_list args, int flags, int length);
int print_int(va_list args, int flags, int length);
int print_binary(va_list args, int flags, int length);
int print_unsigned(va_list args, int flags, int length);
int print_octal(va_list args, int flags, int length);
int print_hex_low(va_list args, int flags, int length);
int print_hex_upp(va_list args, int flags, int length);
int print_S(va_list args, int flags, int length);
int print_pointer(va_list args, int flags, int length);

#endif
