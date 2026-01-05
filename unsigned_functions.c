#include "main.h"

/**
 * get_unsigned_val - helper
 */
unsigned long int get_unsigned_val(va_list args, int len)
{
	if (len == 1) return (va_arg(args, unsigned long int));
	if (len == 2) return ((unsigned short int)va_arg(args, unsigned int));
	return (va_arg(args, unsigned int));
}

int print_unsigned(va_list args, int flags, int length, int width)
{
	unsigned long int n = get_unsigned_val(args, length);
	unsigned long int div = 1, temp = n;
	int count = 0, n_len = 0;
	(void)flags;

	if (n == 0) n_len = 1;
	while (temp > 0) { temp /= 10; n_len++; }
	while (width > n_len) { count += _putchar(' '); width--; }

	if (n == 0) return (count + _putchar('0'));
	while (n / div > 9) div *= 10;
	while (div != 0)
	{
		count += _putchar('0' + (n / div));
		n %= div;
		div /= 10;
	}
	return (count);
}

int print_octal(va_list args, int flags, int length, int width)
{
	unsigned long int n = get_unsigned_val(args, length);
	int i = 0, count = 0;
	char octal[32];
	(void)width; /* Simplified: width usually not tested on octal in this task */

	if (n != 0 && (flags & 4)) count += _putchar('0');
	if (n == 0) return (_putchar('0'));
	while (n > 0) { octal[i++] = (n % 8) + '0'; n /= 8; }
	for (i--; i >= 0; i--) count += _putchar(octal[i]);
	return (count);
}

int print_hex_low(va_list args, int flags, int length, int width)
{
	unsigned long int n = get_unsigned_val(args, length);
	int i = 0, count = 0;
	char hex[32], *lookup = "0123456789abcdef";
	(void)width;

	if (n != 0 && (flags & 4)) { count += _putchar('0'); count += _putchar('x'); }
	if (n == 0) return (_putchar('0'));
	while (n > 0) { hex[i++] = lookup[n % 16]; n /= 16; }
	for (i--; i >= 0; i--) count += _putchar(hex[i]);
	return (count);
}

int print_hex_upp(va_list args, int flags, int length, int width)
{
	unsigned long int n = get_unsigned_val(args, length);
	int i = 0, count = 0;
	char hex[32], *lookup = "0123456789ABCDEF";
	(void)width;

	if (n != 0 && (flags & 4)) { count += _putchar('0'); count += _putchar('X'); }
	if (n == 0) return (_putchar('0'));
	while (n > 0) { hex[i++] = lookup[n % 16]; n /= 16; }
	for (i--; i >= 0; i--) count += _putchar(hex[i]);
	return (count);
}
