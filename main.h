#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct specifier - Struct for specifiers
 * @spec: The character specifier
 * @f: The function pointer (args, flags, width, precision, length)
 */
typedef struct specifier
{
	char spec;
	int (*f)(va_list, int, int, int, int);
} spec_t;

int _putchar(char c);
int _printf(const char *format, ...);
unsigned long int get_unsigned_val(va_list args, int len);

/* Specifiers */
int print_char(va_list args, int f, int w, int p, int l);
int print_string(va_list args, int f, int w, int p, int l);
int print_percent(va_list args, int f, int w, int p, int l);
int print_int(va_list args, int f, int w, int p, int l);
int print_binary(va_list args, int f, int w, int p, int l);
int print_unsigned(va_list args, int f, int w, int p, int l);
int print_octal(va_list args, int f, int w, int p, int l);
int print_hex_low(va_list args, int f, int w, int p, int l);
int print_hex_upp(va_list args, int f, int w, int p, int l);
int print_S(va_list args, int f, int w, int p, int l);
int print_pointer(va_list args, int f, int w, int p, int l);

#endif
