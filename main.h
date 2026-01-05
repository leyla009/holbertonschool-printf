#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct specifier - Struct for specifiers
 * @spec: The specifier (e.g., 'c', 's')
 * @f: The function associated
 */
typedef struct specifier
{
	char spec;
	int (*f)(va_list);
} spec_t;

int _printf(const char *format, ...);
int _putchar(char c);

/* Handler prototypes */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);

#endif
