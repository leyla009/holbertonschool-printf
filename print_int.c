#include "main.h"

/**
 * print_int - Prints an integer with flags, width, precision, and length
 * @args: va_list of arguments
 * @f: flags (1: +, 2: space, 4: #, 8: 0, 16: -)
 * @w: width
 * @p: precision
 * @l: length modifier
 * Return: number of characters printed
 */
int print_int(va_list args, int f, int w, int p, int l)
{
	long int n;
	unsigned long int num, temp, div = 1;
	int count = 0, n_len = 0, p_zeros = 0, total_len;
	char pad = ' ';

	/* 1. Fetch value based on length modifier */
	if (l == 1) n = va_arg(args, long int);
	else if (l == 2) n = (short int)va_arg(args, int);
	else n = va_arg(args, int);

	num = (n < 0) ? -n : n;
	if (num == 0 && p == 0) return (0); /* Case: printf("%.0d", 0) */
	
	/* 2. Calculate actual number length */
	temp = num;
	if (num == 0) n_len = 1;
	while (temp > 0) { temp /= 10; n_len++; }

	/* 3. Calculate precision and total field size */
	if (p > n_len) p_zeros = p - n_len;
	total_len = n_len + p_zeros;
	if (n < 0 || (f & 1) || (f & 2)) total_len++;

	/* 4. Determine padding character (0 flag only works if no - flag and no precision) */
	if ((f & 8) && p < 0 && !(f & 16))
		pad = '0';

	/* 5. Handle Right Alignment (Default behavior) */
	if (!(f & 16))
	{
		/* If using '0' padding, signs must come BEFORE the zeros */
		if (pad == '0')
		{
			if (n < 0) count += _putchar('-');
			else if (f & 1) count += _putchar('+');
			else if (f & 2) count += _putchar(' ');
		}
		while (w > total_len) { count += _putchar(pad); w--; }
	}

	/* 6. Print Sign/Space if not already done by '0' padding */
	if (pad != '0')
	{
		if (n < 0) count += _putchar('-');
		else if (f & 1) count += _putchar('+');
		else if (f & 2) count += _putchar(' ');
	}

	/* 7. Print Precision Zeros and the Number */
	while (p_zeros-- > 0) count += _putchar('0');
	
	while (num / div > 9) div *= 10;
	while (div != 0)
	{
		count += _putchar('0' + (num / div));
		num %= div;
		div /= 10;
	}

	/* 8. Handle Left Alignment (- flag) */
	if (f & 16)
	{
		/* Left alignment always pads with spaces at the end */
		while (w > total_len) { count += _putchar(' '); w--; }
	}

	return (count);
}
