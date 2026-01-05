#include "main.h"

/**
 * print_pointer - Prints the value of a pointer variable
 * @args: va_list containing the pointer to print
 * @flags: active flags
 * Return: Number of characters printed
 */
int print_pointer(va_list args, int flags, int length, int width)
{
	void *p = va_arg(args, void *);
	unsigned long int addr;
	char buffer[16];
	char *hex = "0123456789abcdef";
	int i = 0, count = 0;
	(void)flags;
	(void)length;
	(void)width;

	if (!p)
	{
		char *s = "(nil)";
		while (s[count])
			_putchar(s[count++]);
		return (count);
	}

	addr = (unsigned long int)p;
	count += _putchar('0');
	count += _putchar('x');

	while (addr > 0)
	{
		buffer[i++] = hex[addr % 16];
		addr /= 16;
	}
	for (i--; i >= 0; i--)
		count += _putchar(buffer[i]);

	return (count);
}
