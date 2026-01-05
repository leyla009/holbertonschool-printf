#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct specifier - Struct for specifiers
 * @spec: The character specifier (e.g., 'd', 's')
 * @f: The function pointer associated, accepting flags, width, and length
 */
typedef struct specifier
{
	char spec;
	int (*f)(va_list, int, int, int);
} spec_t;

/* Core Functions */
int _putchar(char c);
int _printf(const char *format, ...);

/* Helper for Unsigned Casting (Task 9) */
unsigned long int get_unsigned_val(va_list args, int len);

/* Specifier Functions (Task 0 - 14) */
/* Signature: (va_list args, int flags, int width, int length) */

int print_char(va_list args, int flags, int width, int length);
int print_string(va_list args, int flags, int width, int length);
int print_percent(va_list args, int flags, int width, int length);
int print_int(va_list args, int flags, int width, int length);
int print_binary(va_list args, int flags, int width, int length);
int print_unsigned(va_list args, int flags, int width, int length);
int print_octal(va_list args, int flags, int width, int length);
int print_hex_low(va_list args, int flags, int width, int length);
int print_hex_upp(va_list args, int flags, int width, int length);
int print_S(va_list args, int flags, int width, int length);
int print_pointer(va_list args, int flags, int width, int length);

#endif /* MAIN_H */
