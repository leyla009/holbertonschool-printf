#include "main.h"

/**
 * get_unsigned_val - Helper to fetch value based on length modifier
 * @args: va_list
 * @len: length modifier (1 for l, 2 for h, 0 for none)
 * Return: the casted unsigned value
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
 * print_unsigned - Prints unsigned int with width, precision, and 0-flag
 */
int print_unsigned(va_list args, int f, int w, int p, int l)
{
	unsigned long int n = get_unsigned_val(args, l);
	unsigned long int div = 1, temp = n;
	int count = 0, n_len = 0, p_zeros = 0, total_len;
	char pad = (f & 8 && p < 0) ? '0' : ' ';

	if (n == 0 && p == 0) return (0);
	if (n == 0) n_len = 1;
	while (temp > 0) { temp /= 10; n_len++; }

	if (p > n_len) p_zeros = p - n_len;
	total_len = n_len + p_zeros;

	while (w > total_len) { count += _putchar(pad); w--; }
	while (p_zeros-- > 0) count += _putchar('0');

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
 * print_octal - Prints octal with width, precision, # and 0 flags
 */
int print_octal(va_list args, int f, int w, int p, int l)
{
	unsigned long int n = get_unsigned_val(args, l);
	unsigned long int temp = n;
	int i = 0, count = 0, n_len = 0, p_zeros = 0, total_len;
	char octal[32], pad = (f & 8 && p < 0) ? '0' : ' ';

	if (n == 0 && p == 0) return (0);
	if (n == 0) n_len = 1;
	while (temp > 0) { temp /= 8; n_len++; }

	if (p > n_len) p_zeros = p - n_len;
	total_len = n_len + p_zeros;
	if (n != 0 && (f & 4)) total_len++;

	if (pad == '0' && n != 0 && (f & 4)) count += _putchar('0');
	while (w > total_len) { count += _putchar(pad); w--; }
	if (pad == ' ' && n != 0 && (f & 4)) count += _putchar('0');
	
	while (p_zeros-- > 0) count += _putchar('0');
	if (n == 0 && p != 0) return (count + _putchar('0'));
	while (n > 0) { octal[i++] = (n % 8) + '0'; n /= 8; }
	for (i--; i >= 0; i--) count += _putchar(octal[i]);
	return (count);
}

/**
 * print_hex_low - Prints lowercase hex with width, precision, # and 0 flags
 */
int print_hex_low(va_list args, int f, int w, int p, int l)
{
	unsigned long int n = get_unsigned_val(args, l);
	unsigned long int temp = n;
	int i = 0, count = 0, n_len = 0, p_zeros = 0, total_len;
	char hex[32], *lookup = "0123456789abcdef";
	char pad = (f & 8 && p < 0) ? '0' : ' ';

	if (n == 0 && p == 0) return (0);
	if (n == 0) n_len = 1;
	while (temp > 0) { temp /= 16; n_len++; }

	if (p > n_len) p_zeros = p - n_len;
	total_len = n_len + p_zeros;
	if (n != 0 && (f & 4)) total_len += 2;

	if (pad == '0' && n != 0 && (f & 4)) { count += _putchar('0'); count += _putchar('x'); }
	while (w > total_len) { count += _putchar(pad); w--; }
	if (pad == ' ' && n != 0 && (f & 4)) { count += _putchar('0'); count += _putchar('x'); }

	while (p_zeros-- > 0) count += _putchar('0');
	if (n == 0 && p != 0) return (count + _putchar('0'));
	while (n > 0) { hex[i++] = lookup[n % 16]; n /= 16; }
	for (i--; i >= 0; i--) count += _putchar(hex[i]);
	return (count);
}

/**
 * print_hex_upp - Prints uppercase hex with width, precision, # and 0 flags
 */
int print_hex_upp(va_list args, int f, int w, int p, int l)
{
	unsigned long int n = get_unsigned_val(args, l);
	unsigned long int temp = n;
	int i = 0, count = 0, n_len = 0, p_zeros = 0, total_len;
	char hex[32], *lookup = "0123456789ABCDEF";
	char pad = (f & 8 && p < 0) ? '0' : ' ';

	if (n == 0 && p == 0) return (0);
	if (n == 0) n_len = 1;
	while (temp > 0) { temp /= 16; n_len++; }

	if (p > n_len) p_zeros = p - n_len;
	total_len = n_len + p_zeros;
	if (n != 0 && (f & 4)) total_len += 2;

	if (pad == '0' && n != 0 && (f & 4)) { count += _putchar('0'); count += _putchar('X'); }
	while (w > total_len) { count += _putchar(pad); w--; }
	if (pad == ' ' && n != 0 && (f & 4)) { count += _putchar('0'); count += _putchar('X'); }

	while (p_zeros-- > 0) count += _putchar('0');
	if (n == 0 && p != 0) return (count + _putchar('0'));
	while (n > 0) { hex[i++] = lookup[n % 16]; n /= 16; }
	for (i--; i >= 0; i--) count += _putchar(hex[i]);
	return (count);
}
