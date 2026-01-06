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

/**
 * print_rot13 - Prints the ROT13'ed string
 */
int print_rot13(va_list args, int f, int w, int precision, int l)
{
	char *s = va_arg(args, char *);
	int i, j, count = 0;
	char in[] =  "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	(void)f; (void)w; (void)precision; (void)l;
	if (!s) s = "(ahyy)";

	for (i = 0; s[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (s[i] == in[j])
			{
				count += _putchar(out[j]);
				break;
			}
		}
		if (!in[j])
			count += _putchar(s[i]);
	}
	return (count);
}
