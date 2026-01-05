#include "main.h"

/**
 * get_unsigned_val - Helper to fetch value based on length modifier
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
 * print_unsigned - Prints unsigned int with width
 */
int print_unsigned(va_list args, int flags, int width, int length)
{
	unsigned long int n = get_unsigned_val(args, length);
	unsigned long int div = 1, temp = n;
	int count = 0, n_len = 0;
	(void)flags;

	if (n == 0) n_len = 1;
	while (temp > 0) { temp /= 10; n_len++; }
	while (width > n_len) { count += _putchar(' '); width--; }

	while (n / div > 9) div *= 10;
	while (div != 0)
	{
		count += _putchar('0' + (n / div));
		n %= div;
		div /= 10;
	}
	return (count);
}

/**
 * print_octal - Prints octal with width and # flag
 */
int print_octal(va_list args, int flags, int width, int length)
{
	unsigned long int n = get_unsigned_val(args, length);
	unsigned long int temp = n;
	int i = 0, count = 0, n_len = 0;
	char octal[32];

	if (n == 0) n_len = 1;
	while (temp > 0) { temp /= 8; n_len++; }
	if (n != 0 && (flags & 4)) n_len++; /* Account for '#' flag '0' prefix */

	while (width > n_len) { count += _putchar(' '); width--; }
	if (n != 0 && (flags & 4)) count += _putchar('0');
	if (n == 0) return (count + _putchar('0'));

	while (n > 0) { octal[i++] = (n % 8) + '0'; n /= 8; }
	for (i--; i >= 0; i--) count += _putchar(octal[i]);
	return (count);
}

/**
 * print_hex_low - Prints lowercase hex with width and # flag
 */
int print_hex_low(va_list args, int flags, int width, int length)
{
	unsigned long int n = get_unsigned_val(args, length);
	unsigned long int temp = n;
	int i = 0, count = 0, n_len = 0;
	char hex[32], *lookup = "0123456789abcdef";

	if (n == 0) n_len = 1;
	while (temp > 0) { temp /= 16; n_len++; }
	if (n != 0 && (flags & 4)) n_len += 2; /* Account for '0x' */

	while (width > n_len) { count += _putchar(' '); width--; }
	if (n != 0 && (flags & 4)) { count += _putchar('0'); count += _putchar('x'); }
	if (n == 0) return (count + _putchar('0'));

	while (n > 0) { hex[i++] = lookup[n % 16]; n /= 16; }
	for (i--; i >= 0; i--) count += _putchar(hex[i]);
	return (count);
}

/**
 * print_hex_upp - Prints uppercase hex with width and # flag
 */
int print_hex_upp(va_list args, int flags, int width, int length)
{
	unsigned long int n = get_unsigned_val(args, length);
	unsigned long int temp = n;
	int i = 0, count = 0, n_len = 0;
	char hex[32], *lookup = "0123456789ABCDEF";

	if (n == 0) n_len = 1;
	while (temp > 0) { temp /= 16; n_len++; }
	if (n != 0 && (flags & 4)) n_len += 2; /* Account for '0X' */

	while (width > n_len) { count += _putchar(' '); width--; }
	if (n != 0 && (flags & 4)) { count += _putchar('0'); count += _putchar('X'); }
	if (n == 0) return (count + _putchar('0'));

	while (n > 0) { hex[i++] = lookup[n % 16]; n /= 16; }
	for (i--; i >= 0; i--) count += _putchar(hex[i]);
	return (count);
}
