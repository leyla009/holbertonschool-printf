#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct specifier - Struct for specifiers
 * @spec: The character (c, s, d, i, b, etc.)
 * @f: The function pointer associated with the specifier
 */
typedef struct specifier
{
    char spec;
    int (*f)(va_list);
} spec_t;

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_binary(va_list args);
int recursive_int(unsigned int num);

#endif
