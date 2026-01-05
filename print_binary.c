#include "main.h"

/**
 * print_binary - converts and prints an unsigned int in binary
 * @args: va_list containing the unsigned int
 * Return: number of characters printed
 */
int print_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int m, i, sum;
	unsigned int a[32];
	int count = 0;

	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
