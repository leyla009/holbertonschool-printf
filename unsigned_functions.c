#include "main.h"

int print_unsigned(va_list args, int flags, int length, int width)
{
	unsigned long int n = get_unsigned_val(args, length);
	unsigned long int div = 1, temp = n;
	int count = 0, n_len = 0;
	(void)flags;

	/* Calculate content length */
	if (n == 0) n_len = 1;
	while (temp > 0) { temp /= 10; n_len++; }

	/* Print spaces for width padding */
	while (width > n_len)
	{
		count += _putchar(' ');
		width--;
	}

	/* Print digits */
	if (n == 0) return (count + _putchar('0'));
	while (n / div > 9) div *= 10;
	while (div != 0)
	{
		count += _putchar('0' + (n / div));
		n %= div;
		div /= 10;
	}
	return (count);
}
