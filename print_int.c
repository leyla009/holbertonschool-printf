#include "main.h"

/**
 * print_int - Prints an integer with field width, flags, and length modifiers
 * @args: va_list of arguments
 * @flags: active flags (+, space)
 * @width: field width
 * @length: length modifier (l, h)
 * Return: number of characters printed
 */
int print_int(va_list args, int flags, int length, int width)
{
	long int n;
	unsigned long int num, temp, div = 1;
	int count = 0, n_len = 0;

	/* 1. Extract the number with length modifier logic */
	if (length == 1)
		n = va_arg(args, long int);
	else if (length == 2)
		n = (short int)va_arg(args, int);
	else
		n = va_arg(args, int);

	num = (n < 0) ? -n : n;
	temp = num;

	/* 2. Calculate digit length */
	if (num == 0)
		n_len = 1;
	else
	{
		while (temp > 0)
		{
			temp /= 10;
			n_len++;
		}
	}

	/* 3. Account for sign/space length BEFORE printing padding */
	if (n < 0 || (flags & 1) || (flags & 2))
		n_len++;

	/* 4. Print Width Padding (Spaces) first for right alignment */
	while (width > n_len)
	{
		count += _putchar(' ');
		width--;
	}

	/* 5. Print the Sign (if any) */
	if (n < 0)
		count += _putchar('-');
	else if (flags & 1)
		count += _putchar('+');
	else if (flags & 2)
		count += _putchar(' ');

	/* 6. Print the actual digits */
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
