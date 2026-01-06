#include "main.h"

int print_int(va_list args, int flags, int width, int precision, int length)
{
	long int n;
	unsigned long int num, temp, div = 1;
	int count = 0, n_len = 0, p_zeros = 0, total_len;

	if (length == 1) n = va_arg(args, long int);
	else if (length == 2) n = (short int)va_arg(args, int);
	else n = va_arg(args, int);

	num = (n < 0) ? -n : n;
	if (num == 0 && precision == 0) return (0);

	temp = num;
	if (num == 0) n_len = 1;
	while (temp > 0) { temp /= 10; n_len++; }

	if (precision > n_len) p_zeros = precision - n_len;
	total_len = n_len + p_zeros;
	if (n < 0 || (flags & 1) || (flags & 2)) total_len++;

	while (width > total_len) { count += _putchar(' '); width--; }

	if (n < 0) count += _putchar('-');
	else if (flags & 1) count += _putchar('+');
	else if (flags & 2) count += _putchar(' ');

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
