#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct specifier
{
	char spec;
	int (*f)(va_list, int);
} spec_t;

int _putchar(char c);
int _printf(const char *format, ...);

int print_char(va_list args, int flags);
int print_string(va_list args, int flags);
int print_percent(va_list args, int flags);
int print_int(va_list args, int flags);
int print_binary(va_list args, int flags);
int print_unsigned(va_list args, int flags);
int print_octal(va_list args, int flags);
int print_hex_low(va_list args, int flags);
int print_hex_upp(va_list args, int flags);
int print_S(va_list args, int flags);
int print_pointer(va_list args, int flags);

#endif
