#include "main.h"

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

int print_octal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int i = 0, count = 0;
	char octal[32];

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

int print_hex_low(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int i = 0, count = 0;
	char hex[32];
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

int print_hex_upp(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int i = 0, count = 0;
	char hex[32];
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
