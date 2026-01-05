#include "main.h"

/**
 * print_char - Prints a character
 * @args: va_list
 * @flags: active flags (unused)
 * Return: 1
 */
int print_char(va_list args, int flags)
{
	(void)flags;
	return (_putchar(va_arg(args, int)));
}

/**
 * print_string - Prints a string
 * @args: va_list
 * @flags: active flags (unused)
 * Return: number of chars printed
 */
int print_string(va_list args, int flags)
{
	char *s = va_arg(args, char *);
	int i, count = 0;
	(void)flags;

	if (!s)
		s = "(null)";
	for (i = 0; s[i]; i++)
		count += _putchar(s[i]);
	return (count);
}

/**
 * print_percent - Prints %
 * @args: va_list
 * @flags: active flags (unused)
 * Return: 1
 */
int print_percent(va_list args, int flags)
{
	(void)args;
	(void)flags;
	return (_putchar('%'));
}

/**
 * print_binary - Prints binary
 * @args: va_list
 * @flags: active flags (unused)
 * Return: number of chars printed
 */
int print_binary(va_list args, int flags)
{
	unsigned int n = va_arg(args, unsigned int);
	int i = 0, count = 0;
	char binary[64];
	(void)flags;

	if (n == 0)
		return (_putchar('0'));
	while (n > 0)
	{
		binary[i++] = (n % 2) + '0';
		n /= 2;
	}
	for (i--; i >= 0; i--)
		count += _putchar(binary[i]);
	return (count);
}
