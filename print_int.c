#include "main.h"

/**
 * print_int - prints an integer
 * @args: list of arguments
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	unsigned int num;

	/* Handle negative numbers */
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		num = -n;
	}
	else
	{
		num = n;
	}

	count += recursive_int(num);
	return (count);
}

/**
 * recursive_int - helper function to print digits using recursion
 * @num: the unsigned integer to print
 * Return: number of digits printed
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
