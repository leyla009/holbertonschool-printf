#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct specifier - Struct for specifiers
 * @spec: The character specifier (e.g., c, s, d, i...)
 * @f: The function pointer associated with the specifier
 */
typedef struct specifier
{
	char spec;
	int (*f)(va_list);
} spec_t;

/* --- Task 5: Buffer Management & Main Engine --- */

int _putchar(char c);
int _printf(const char *format, ...);

/* --- Task 0: Character and Strings --- */

/**
 * print_char - Prints a character
 * @args: va_list containing the character
 * Return: Number of characters printed
 */
int print_char(va_list args);

/**
 * print_string - Prints a string
 * @args: va_list containing the string
 * Return: Number of characters printed
 */
int print_string(va_list args);

/**
 * print_percent - Prints a percent sign
 * @args: va_list (unused)
 * Return: Number of characters printed
 */
int print_percent(va_list args);

/* --- Task 1: Integers (%d and %i) --- */

/**
 * print_int - Prints an integer (decimal and integer)
 * @args: va_list containing the integer
 * Return: Number of characters printed
 */
int print_int(va_list args);

/* --- Task 3: Custom Binary (%b) --- */

/**
 * print_binary - Converts and prints an unsigned int to binary
 * @args: va_list containing the unsigned int
 * Return: Number of characters printed
 */
int print_binary(va_list args);

/* --- Task 4: Unsigned, Octal, and Hexadecimal --- */

/**
 * print_unsigned - Prints an unsigned decimal integer
 * @args: va_list containing the unsigned int
 * Return: Number of characters printed
 */
int print_unsigned(va_list args);

/**
 * print_octal - Prints an unsigned int in octal notation
 * @args: va_list containing the unsigned int
 * Return: Number of characters printed
 */
int print_octal(va_list args);

/**
 * print_hex_low - Prints an unsigned int in lowercase hexadecimal
 * @args: va_list containing the unsigned int
 * Return: Number of characters printed
 */
int print_hex_low(va_list args);

/**
 * print_hex_upp - Prints an unsigned int in uppercase hexadecimal
 * @args: va_list containing the unsigned int
 * Return: Number of characters printed
 */
int print_hex_upp(va_list args);

/* --- Task 6: Custom String (%S) --- */

/**
 * print_S - Prints a string with non-printable characters as hex values
 * @args: va_list containing the string
 * Return: Number of characters printed
 */
int print_S(va_list args);
/* --- Task 7: Pointer (%p) --- */

/**
 * print_pointer - Prints the address of a pointer in hex
 * @args: va_list containing the pointer
 * Return: Number of characters printed
 */
int print_pointer(va_list args);

#endif /* MAIN_H */
