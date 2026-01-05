#include "main.h"

/**
 * print_char - Prints a character
 * @args: va_list
 * @flags: flags
 * @length: length
 * @width: width
 * Return: number of chars printed
 */
int print_char(va_list args, int flags, int length, int width)
{
	int count = 0;
	(void)flags; (void)length;

	while (width > 1)
	{
		count += _putchar(' ');
		width--;
	}
	count += _putchar(va_arg(args, int));
	return (count);
}

/**
 * print_string - Prints a string
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
 * print_percent - Prints percent sign
 */
int print_percent(va_list args, int flags, int length, int width)
{
	(void)args; (void)flags; (void)length; (void)width;
	return (_putchar('%'));
}

/**
 * print_binary - Prints binary
 */
int print_binary(va_list args, int flags, int length, int width)
{
	unsigned int n = va_arg(args, unsigned int);
	int i = 0, count = 0;
	char binary[64];
	(void)flags; (void)length; (void)width;

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
