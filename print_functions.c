#include "main.h"

/**
 * print_char - Prints a character with width padding
 * @args: va_list
 * @flags: flags
 * @width: field width
 * @length: length modifier
 * Return: number of characters printed
 */
int print_char(va_list args, int flags, int width, int length)
{
	int count = 0;
	char c = va_arg(args, int);

	(void)flags;
	(void)length;

	/* Write leading spaces if width > 1 */
	while (width > 1)
	{
		count += _putchar(' ');
		width--;
	}

	count += _putchar(c);
	return (count);
}

/**
 * print_string - Prints a string with width padding
 */
int print_string(va_list args, int flags, int width, int length)
{
	char *s = va_arg(args, char *);
	int i, len = 0, count = 0;

	(void)flags;
	(void)length;

	if (!s)
		s = "(null)";

	while (s[len])
		len++;

	/* Print leading spaces for width padding */
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
 * print_percent - Prints a percent sign
 */
int print_percent(va_list args, int flags, int width, int length)
{
	(void)args;
	(void)flags;
	(void)width;
	(void)length;

	return (_putchar('%'));
}

/**
 * print_binary - Prints unsigned int in binary
 */
int print_binary(va_list args, int flags, int width, int length)
{
	unsigned int n = va_arg(args, unsigned int);
	int i = 0, count = 0;
	char binary[64];

	(void)flags;
	(void)width;
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
