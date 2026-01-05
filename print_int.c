#include "main.h"

/**
 * print_int - Prints an integer with + and space flags
 * @args: va_list
 * @flags: flag identifiers
 * Return: number of chars printed
 */
int print_int(va_list args, int flags)
{
	int n = va_arg(args, int);
	unsigned int num;
	unsigned int div = 1;
	int count = 0;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
	{
		if (flags & 1) /* '+' flag */
			count += _putchar('+');
		else if (flags & 2) /* ' ' flag */
			count += _putchar(' ');
		num = n;
	}

	while (num / div > 9)
		div *= 10;
	while (div != 0)
	{
		count += _putchar('0' + (num / div));
		num %= div;
		div /= 10;
	}
	return (count);
}
