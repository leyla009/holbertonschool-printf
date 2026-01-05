#include "main.h"

/**
 * get_unsigned_val - Fetches an unsigned number based on length modifier
 * @args: va_list of arguments
 * @len: Length modifier (1 for l, 2 for h, 0 for default)
 * Return: The number as an unsigned long int
 */
unsigned long int get_unsigned_val(va_list args, int len)
{
	if (len == 1)
		return (va_arg(args, unsigned long int));
	if (len == 2)
		return ((unsigned short int)va_arg(args, unsigned int));
	return (va_arg(args, unsigned int));
}

/**
 * print_unsigned - Prints an unsigned integer with field width
 * @args: va_list
 * @flags: Active flags (unused for u)
 * @len: Length modifier
 * @width: Field width
 * Return: Number of characters printed
 */
int print_unsigned(va_list args, int flags, int len, int width)
{
	unsigned long int n = get_unsigned_val(args, len);
	unsigned long int div = 1, temp = n;
	int count = 0, n_len = 0;

	(void)flags;

	/* Calculate content length */
	if (n == 0)
		n_len = 1;
	while (temp > 0)
	{
		temp /= 10;
		n_len++;
	}

	/* Print leading spaces for width */
	while (width > n_len)
	{
		count += _putchar(' ');
		width--;
	}

	/* Print digits */
	while (n / div > 9)
		div *= 10;

	while (div != 0)
	{
		count += _putchar('0' + (n / div));
		n %= div;
		div /= 10;
	}
	return (count);
}

/**
 * print_octal - Prints an unsigned int in octal with width and # flag
 */
int print_octal(va_list args, int flags, int len, int width)
{
	unsigned long int n = get_unsigned_val(args, len);
	unsigned long int temp = n;
	int i = 0, count = 0, n_len = 0;
	char octal[32];

	/* Calculate content length */
	if (n == 0)
		n_len = 1;
	while (temp > 0)
	{
		temp /= 8;
		n_len++;
	}
	if (n != 0 && (flags & 4))
		n_len++;

	/* Padding */
	while (width > n_len)
	{
		count += _putchar(' ');
		width--;
	}

	if (n != 0 && (flags & 4))
		count += _putchar('0');

	if (n == 0)
		return (count + _putchar('0'));

	while (n > 0)
	{
		octal[i++] = (n % 8) + '0';
		n /= 8;
	}
	for (i--; i >= 0; i--)
		count += _putchar(octal[i]);
	return (count);
}

/**
 * print_hex_low - Prints hex in lowercase with width and # flag
 */
int print_hex_low(va_list args, int flags, int len, int width)
{
	unsigned long int n = get_unsigned_val(args, len);
	unsigned long int temp = n;
	int i = 0, count = 0, n_len = 0;
	char hex[32], *lookup = "0123456789abcdef";

	/* Calculate length */
	if (n == 0)
		n_len = 1;
	while (temp > 0)
	{
		temp /= 16;
		n_len++;
	}
	if (n != 0 && (flags & 4))
		n_len += 2;

	/* Padding */
	while (width > n_len)
	{
		count += _putchar(' ');
		width--;
	}

	if (n != 0 && (flags & 4))
	{
		count += _putchar('0');
		count += _putchar('x');
	}

	if (n == 0)
		return (count + _putchar('0'));

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
 * print_hex_upp - Prints hex in uppercase with width and # flag
 */
int print_hex_upp(va_list args, int flags, int len, int width)
{
	unsigned long int n = get_unsigned_val(args, len);
	unsigned long int temp = n;
	int i = 0, count = 0, n_len = 0;
	char hex[32], *lookup = "0123456789ABCDEF";

	/* Calculate length */
	if (n == 0)
		n_len = 1;
	while (temp > 0)
	{
		temp /= 16;
		n_len++;
	}
	if (n != 0 && (flags & 4))
		n_len += 2;

	/* Padding */
	while (width > n_len)
	{
		count += _putchar(' ');
		width--;
	}

	if (n != 0 && (flags & 4))
	{
		count += _putchar('0');
		count += _putchar('X');
	}

	if (n == 0)
		return (count + _putchar('0'));

	while (n > 0)
	{
		hex[i++] = lookup[n % 16];
		n /= 16;
	}
	for (i--; i >= 0; i--)
		count += _putchar(hex[i]);
	return (count);
}
