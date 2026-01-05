#include "main.h"

/**
 * print_int - Prints an integer
 */
int print_int(va_list args, int flags, int length, int width)
{
	long int n;
	unsigned long int num, temp, div = 1;
	int count = 0, n_len = 0;

	if (length == 1) n = va_arg(args, long int);
	else if (length == 2) n = (short int)va_arg(args, int);
	else n = va_arg(args, int);

	num = (n < 0) ? -n : n;
	temp = num;
	if (num == 0) n_len = 1;
	while (temp > 0) { temp /= 10; n_len++; }
	if (n < 0 || (flags & 1) || (flags & 2)) n_len++;

	while (width > n_len)
	{
		count += _putchar(' ');
		width--;
	}

	if (n < 0) count += _putchar('-');
	else if (flags & 1) count += _putchar('+');
	else if (flags & 2) count += _putchar(' ');

	while (num / div > 9) div *= 10;
	while (div != 0)
	{
		count += _putchar('0' + (num / div));
		num %= div;
		div /= 10;
	}
	return (count);
}
