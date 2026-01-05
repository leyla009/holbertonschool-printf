#include "main.h"

/**
 * print_int - Prints an integer
 * @args: va_list containing the integer to print
 * Return: Number of characters printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	unsigned int num;
	unsigned int div = 1;
	int count = 0;

	/* Handle negative numbers */
	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	/* Calculate divisor */
	while (num / div > 9)
		div *= 10;

	/* Print digits using the divisor */
	while (div != 0)
	{
		count += _putchar('0' + (num / div));
		num %= div;
		div /= 10;
	}

	return (count);
}
