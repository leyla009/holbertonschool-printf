#include "main.h"

/**
 * print_int - Prints an integer with precision, width, and flags
 * @args: va_list
 * @f: flags
 * @w: width
 * @p: precision
 * @l: length modifier
 * Return: Number of characters printed
 */
int print_int(va_list args, int f, int w, int p, int l)
{
	long int n;
	unsigned long int num, temp, div = 1;
	int count = 0, n_len = 0, p_zeros = 0, total_len;
	char pad = ' ';

	if (l == 1) n = va_arg(args, long int);
	else if (l == 2) n = (short int)va_arg(args, int);
	else n = va_arg(args, int);

	num = (n < 0) ? -n : n;

	/* Calculate number length (0 is special if precision is 0) */
	if (!(num == 0 && p == 0))
	{
		temp = num;
		if (num == 0) n_len = 1;
		while (temp > 0) { temp /= 10; n_len++; }
	}

	/* Calculate precision zeros */
	if (p > n_len) p_zeros = p - n_len;

	/* Calculate total length including signs and precision */
	total_len = n_len + p_zeros;
	if (n < 0 || (f & 1) || (f & 2)) total_len++;

	/* Determine padding char (0 flag is ignored if precision is set or '-' flag exists) */
	if ((f & 8) && p < 0 && !(f & 16)) pad = '0';

	/* 1. Right align padding */
	if (!(f & 16))
	{
		if (pad == '0') /* Sign comes before 0-padding */
		{
			if (n < 0) count += _putchar('-');
			else if (f & 1) count += _putchar('+');
			else if (f & 2) count += _putchar(' ');
		}
		while (w > total_len) { count += _putchar(pad); w--; }
	}

	/* 2. Print Sign (if not already done by 0-padding) */
	if (pad != '0')
	{
		if (n < 0) count += _putchar('-');
		else if (f & 1) count += _putchar('+');
		else if (f & 2) count += _putchar(' ');
	}

	/* 3. Print Precision Zeros */
	while (p_zeros-- > 0) count += _putchar('0');

	/* 4. Print Digits (Skip if n is 0 and precision is 0) */
	if (!(num == 0 && p == 0))
	{
		while (num / div > 9) div *= 10;
		while (div != 0)
		{
			count += _putchar('0' + (num / div));
			num %= div;
			div /= 10;
		}
	}

	/* 5. Left align padding */
	if (f & 16)
	{
		while (w > total_len) { count += _putchar(' '); w--; }
	}

	return (count);
}
