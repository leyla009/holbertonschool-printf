#include "main.h"

/**
 * print_int - Prints an integer with flags and length modifiers
 * @args: va_list
 * @flags: +, space, #
 * @length: l or h
 * Return: count
 */
int print_int(va_list args, int flags, int length)
{
	long int n;
	unsigned long int num, div = 1;
	int count = 0;

	if (length == 1) n = va_arg(args, long int);
	else if (length == 2) n = (short int)va_arg(args, int);
	else n = va_arg(args, int);

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
	{
		if (flags & 1) count += _putchar('+');
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
