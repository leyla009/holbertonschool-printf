#include "main.h"

/**
 * print_int - prints an integer
 * @args: va_list
 * Return: number of chars printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		num = -n;
	}
	else
		num = n;

	count += recursive_int(num);
	return (count);
}

/**
 * recursive_int - prints digits
 * @num: unsigned int
 * Return: count
 */
int recursive_int(unsigned int num)
{
	int count = 0;
	char digit;

	if (num / 10)
		count += recursive_int(num / 10);

	digit = (num % 10) + '0';
	write(1, &digit, 1);
	count++;
	return (count);
}
