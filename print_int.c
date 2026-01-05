#include "main.h"

/**
 * print_int - Prints an integer with flags and length modifiers
 * @args: va_list
 * @flags: +, space, #
 * @length: l or h
 * Return: count
 */
int print_int(va_list args, int flags, int length, int width)
{
	long int n;
	unsigned long int num, temp;
	int count = 0, n_len = 0;

	if (length == 1) n = va_arg(args, long int);
	else if (length == 2) n = (short int)va_arg(args, int);
	else n = va_arg(args, int);

	num = (n < 0) ? -n : n;
	temp = num;
	
	/* Calculate number length */
	if (num == 0) n_len = 1;
	while (temp > 0) { temp /= 10; n_len++; }
	if (n < 0 || (flags & 1) || (flags & 2)) n_len++;

	/* Print Width Padding */
	while (width > n_len)
	{
		count += _putchar(' ');
		width--;
	}

	/* Actual printing */
	if (n < 0) count += _putchar('-');
	else if (flags & 1) count += _putchar('+');
	else if (flags & 2) count += _putchar(' ');
		num = n;
	}

	while (num / div > 9) div *= 10;
	while (div != 0)
	{
		count += _putchar('0' + (num / div));
		num %= div;
		div /= 10;
	}
	return (count);
}
