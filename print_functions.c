#include "main.h"

/**
 * print_binary - Prints an unsigned int in binary
 * @args: va_list
 * @f: flags
 * @w: width
 * @precision: precision (renamed from p)
 * @l: length
 * Return: number of characters printed
 */

int print_binary(va_list args, int f, int w, int precision, int l)
{
	unsigned int n = va_arg(args, unsigned int);
	int i = 0, count = 0;
	char binary[64];

	(void)f;
	(void)w;
	(void)precision;
	(void)l;

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
int print_char(va_list args, int f, int w, int precision, int l)
{
	int count = 0;
	char c = va_arg(args, int);
	
	(void)f; (void)precision; (void)l;
	while (w > 1) { count += _putchar(' '); w--; }
	return (count + _putchar(c));
}

int print_string(va_list args, int f, int w, int precision, int l)
{
	char *s = va_arg(args, char *);
	int i, len = 0, count = 0;
	(void)f; 
	(void)l;

	if (!s) 
		s = "(null)";
	while (s[len]) 
		len++;
	if (precision >= 0 && precision < len) len = precision;

	if (precision >= 0 && precision < len)
		len = precision;
	while (w > len) { count += _putchar(' '); w--; }
	for (i = 0; i < len; i++) count += _putchar(s[i]);
	return (count);
}

int print_percent(va_list args, int f, int w, int precision, int l)
{
	(void)args; (void)f; (void)w; (void)precision; (void)l;
	return (_putchar('%'));
}
