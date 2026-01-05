#include "main.h"

/**
 * print_char - Prints a character
 * @args: va_list
 * @flags: active flags (unused)
 * Return: 1
 */
int print_char(va_list args, int flags, int length)
{
	(void)flags;
	(void)length;
	return (_putchar(va_arg(args, int)));
}

/**
 * print_string - Prints a string
 * @args: va_list
 * @flags: active flags (unused)
 * Return: number of chars printed
 */

int print_string(va_list args, int flags, int length, int width)
{
	char *s = va_arg(args, char *);
	int i, len = 0, count = 0;
	(void)flags; (void)length;

	if (!s)
		s = "(null)";

	while (s[len])
		len++;

	/* Padding logic */
	while (width > len)
	{
		count += _putchar(' ');
		width--;
	}

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
int print_percent(va_list args, int flags, int length)
{
	(void)args;
	(void)flags;
	(void)length;
	return (_putchar('%'));
}

/**
 * print_binary - Prints binary
 * @args: va_list
 * @flags: active flags (unused)
 * Return: number of chars printed
 */
int print_binary(va_list args, int flags, int length)
{
	unsigned int n = va_arg(args, unsigned int);
	int i = 0, count = 0;
	char binary[64];
	(void)flags;
	(void)length;
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
