#include "main.h"

/**
 * print_S - prints a string and non-printable characters as \x followed
 * by the ASCII code value in hexadecimal (upper case - always 2 characters)
 * @args: va_list containing the string
 * Return: number of characters printed
 */
int print_S(va_list args)
{
	char *s = va_arg(args, char *);
	int i, count = 0;
	char *hex = "0123456789ABCDEF";

	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i] != '\0'; i++)
	{
		/* Check if character is non-printable */
		if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			
			/* Print high nibble (first hex digit) */
			count += _putchar(hex[(unsigned char)s[i] / 16]);
			/* Print low nibble (second hex digit) */
			count += _putchar(hex[(unsigned char)s[i] % 16]);
		}
		else
		{
			count += _putchar(s[i]);
		}
	}
	return (count);
}
