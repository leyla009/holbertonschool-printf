#include "main.h"

int print_char(va_list args)
{
	return (_putchar(va_arg(args, int)));
}

int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int i, count = 0;

	if (!s) s = "(null)";
	for (i = 0; s[i]; i++)
		count += _putchar(s[i]);
	return (count);
}

int print_percent(va_list args)
{
	(void)args;
	return (_putchar('%'));
}

int print_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int i = 0, count = 0;
	char binary[64];

	if (n == 0) return (_putchar('0'));
	while (n > 0)
	{
		binary[i++] = (n % 2) + '0';
		n /= 2;
	}
	for (i--; i >= 0; i--)
		count += _putchar(binary[i]);
	return (count);
}
