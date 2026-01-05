#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer in decimal (base 10)
 * @args: va_list containing the unsigned int
 * Return: Number of characters printed
 */
int print_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int div = 1;
	int len = 0;

	if (n == 0)
		return (_putchar('0'));

	while (n / div > 9)
		div *= 10;

	while (div != 0)
	{
		len += _putchar('0' + (n / div));
		n %= div;
		div /= 10;
	}
	return (len);
}

/**
 * print_octal - Prints an unsigned integer in octal (base 8)
 * @args: va_list containing the unsigned int
 * Return: Number of characters printed
 */
int print_octal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int i = 0, count = 0;
	int octal[11]; /* Max unsigned int in octal is 11 digits */

	if (n == 0)
		return (_putchar('0'));

	while (n > 0)
	{
		octal[i++] = n % 8;
		n /= 8;
	}

	for (i--; i >= 0; i--)
		count += _putchar(octal[i] + '0');

	return (count);
}

/**
 * print_hex_low - Prints hex in lowercase
 * @args: va_list containing the unsigned int
 * Return: Number of characters printed
 */
int print_hex_low(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int i = 0, count = 0;
	char hex[8]; /* Max unsigned int in hex is 8 digits */
	char *lookup = "0123456789abcdef";

	if (n == 0)
		return (_putchar('0'));

	while (n > 0)
	{
		hex[i++] = lookup[n % 16];
		n /= 16;
	}

	for (i--; i >= 0; i--)
		count += _putchar(hex[i]);

	return (count);
}

/**
 * print_hex_upp - Prints hex in uppercase
 * @args: va_list containing the unsigned int
 * Return: Number of characters printed
 */
int print_hex_upp(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int i = 0, count = 0;
	char hex[8];
	char *lookup = "0123456789ABCDEF";

	if (n == 0)
		return (_putchar('0'));

	while (n > 0)
	{
		hex[i++] = lookup[n % 16];
		n /= 16;
	}

	for (i--; i >= 0; i--)
		count += _putchar(hex[i]);

	return (count);
}
