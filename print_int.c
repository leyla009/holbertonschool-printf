#include "main.h"

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
	if (num == 0 && p == 0) return (0);
	temp = num;
	if (num == 0) n_len = 1;
	while (temp > 0) { temp /= 10; n_len++; }

	if (p > n_len) p_zeros = p - n_len;
	total_len = n_len + p_zeros;
	if (n < 0 || (f & 1) || (f & 2)) total_len++;

	/* Handle 0-flag logic */
	if ((f & 8) && p < 0)
	{
		pad = '0';
		if (n < 0) count += _putchar('-');
		else if (f & 1) count += _putchar('+');
		else if (f & 2) count += _putchar(' ');
	}

	while (w > total_len) { count += _putchar(pad); w--; }

	/* If not already printed by 0-flag logic */
	if (!((f & 8) && p < 0))
	{
		if (n < 0) count += _putchar('-');
		else if (f & 1) count += _putchar('+');
		else if (f & 2) count += _putchar(' ');
	}

	while (p_zeros-- > 0) count += _putchar('0');
	while (num / div > 9) div *= 10;
	while (div != 0)
	{
		count += _putchar('0' + (num / div));
		num %= div;
		div /= 10;
	}
	return (count);
}
