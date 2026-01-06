#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct specifier - Struct for specifiers
 * @spec: The character specifier (e.g., 'd', 's')
 * @f: The function pointer associated with the specifier
 */
typedef struct specifier
{
	char spec;
	int (*f)(va_list, int, int, int, int);
} spec_t;

/* --- Core Logic Functions --- */
int _putchar(char c);
int _printf(const char *format, ...);
unsigned long int get_unsigned_val(va_list args, int len);

/* --- Specifier Functions --- */
/* Signature: (va_list args, int flags, int width, int precision, int length) */

/* Basic Functions (print_functions.c) */
int print_char(va_list args, int f, int w, int precision, int l);
int print_string(va_list args, int f, int w, int precision, int l);
int print_percent(va_list args, int f, int w, int precision, int l);
int print_binary(va_list args, int f, int w, int precision, int l);

/* Integer Functions (print_int.c) */
int print_int(va_list args, int f, int w, int precision, int l);

/* Unsigned & Bases (unsigned_functions.c) */
int print_unsigned(va_list args, int f, int w, int precision, int l);
int print_octal(va_list args, int f, int w, int precision, int l);
int print_hex_low(va_list args, int f, int w, int precision, int l);
int print_hex_upp(va_list args, int f, int w, int precision, int l);

/* Custom String Functions (custom_string_functions.c) */
int print_S(va_list args, int f, int w, int precision, int l);

/* Pointer Functions (pointer_functions.c) */
int print_pointer(va_list args, int f, int w, int precision, int l);


int print_rev(va_list args, int f, int w, int precision, int l);
int print_rot13(va_list args, int f, int w, int precision, int l);

#endif /* MAIN_H */
