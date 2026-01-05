#include "main.h"

/**
 * get_unsigned_val - Fetches an unsigned number from va_list based on length
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
 * print_unsigned - Prints an unsigned integer
 * @args: va_list
 * @flags: Active flags
 * @len: Length modifier
 * Return: Number of characters printed
 */
int print_unsigned(va_list args, int flags, int len)
{
	unsigned long int n = get_unsigned_val(args, len);
	unsigned long int div = 1;
	int count = 0;

	(void)flags;

	if (n == 0)
		return (_putchar('0'));

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
 * print_octal - Prints an unsigned int in octal
 * @args: va_list
 * @flags: Active flags (handles #)
 * @len: Length modifier
 * Return: Number of characters printed
 */
int print_octal(va_list args, int flags, int len)
{
	unsigned long int n = get_unsigned_val(args, len);
	int i = 0, count = 0;
	char octal[32];

	if (n != 0 && (flags & 4)) /* '#' flag for octal */
		count += _putchar('0');

	if (n == 0)
		return (_putchar('0'));

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
 * print_hex_low - Prints unsigned int in lowercase hex
 * @args: va_list
 * @flags: Active flags (handles #)
 * @len: Length modifier
 * Return: Number of characters printed
 */
int print_hex_low(va_list args, int flags, int len)
{
	unsigned long int n = get_unsigned_val(args, len);
	int i = 0, count = 0;
	char hex[32];
	char *lookup = "0123456789abcdef";

	if (n != 0 && (flags & 4)) /* '#' flag: prefix 0x */
	{
		count += _putchar('0');
		count += _putchar('x');
	}

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
 * print_hex_upp - Prints unsigned int in uppercase hex
 * @args: va_list
 * @flags: Active flags (handles #)
 * @len: Length modifier
 * Return: Number of characters printed
 */
int print_hex_upp(va_list args, int flags, int len)
{
	unsigned long int n = get_unsigned_val(args, len);
	int i = 0, count = 0;
	char hex[32];
	char *lookup = "0123456789ABCDEF";

	if (n != 0 && (flags & 4)) /* '#' flag: prefix 0X */
	{
		count += _putchar('0');
		count += _putchar('X');
	}

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
