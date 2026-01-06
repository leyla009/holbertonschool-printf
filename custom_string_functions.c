#include "main.h"

/**
 * print_S - Prints a string and the hex value of non-printable characters
 * @args: va_list of arguments
 * @f: flags
 * @w: width
 * @precision: precision
 * @l: length modifier
 * Return: Number of characters printed
 */
int print_S(va_list args, int f, int w, int precision, int l)
{
	char *s = va_arg(args, char *);
	int i, count = 0;
	char *hex = "0123456789ABCDEF";

	(void)f; (void)w; (void)precision; (void)l;

	if (!s)
		s = "(null)";

	for (i = 0; s[i]; i++)
	{
		/* Check if character is non-printable */
		if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			/* Always print 2 digits for hex */
			count += _putchar(hex[(unsigned char)s[i] / 16]);
			count += _putchar(hex[(unsigned char)s[i] % 16]);
		}
		else
		{
			count += _putchar(s[i]);
		}
	}
	return (count);
}

/**
 * print_rev - Prints a string in reverse
 * @args: va_list of arguments
 * @f: flags
 * @w: width
 * @precision: precision
 * @l: length modifier
 * Return: Number of characters printed
 */
int print_rev(va_list args, int f, int w, int precision, int l)
{
	char *s = va_arg(args, char *);
	int i, len = 0, count = 0;

	(void)precision; (void)l;

	if (!s)
		s = ")llun(";

	while (s[len])
		len++;

	/* Handle Right Alignment padding (Default) */
	if (!(f & 16))
	{
		while (w > len)
		{
			count += _putchar(' ');
			w--;
		}
	}

	/* Print the string backwards */
	for (i = len - 1; i >= 0; i--)
		count += _putchar(s[i]);

	/* Handle Left Alignment padding (-) */
	if (f & 16)
	{
		while (w > len)
		{
			count += _putchar(' ');
			w--;
		}
	}

	return (count);
}
