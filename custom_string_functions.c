#include "main.h"

/**
 * print_S - Prints string with hex for non-printables
 * @args: va_list
 * @f: active flags (unused)
 * @w: width
 * @precision: precision
 * @l: length
 * Return: number of chars printed
 */
int print_S(va_list args, int f, int w, int precision, int l) 
{
	char *s = va_arg(args, char *);
	int i, count = 0;
	char *hex = "0123456789ABCDEF";

	(void)f; (void) w; (void)precision; (void)l;

	if (!s)
		s = "(null)";

	for (i = 0; s[i]; i++)
	{
		if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			count += _putchar(hex[(unsigned char)s[i] / 16]);
			count += _putchar(hex[(unsigned char)s[i] % 16]);
		}
		else
			count += _putchar(s[i]);
	}
	return (count);
}
