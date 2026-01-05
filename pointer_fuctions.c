#include "main.h"

/**
 * print_pointer - Prints the value of a pointer variable
 * @args: va_list containing the pointer to print
 * Return: Number of characters printed
 */
int print_pointer(va_list args)
{
	void *p = va_arg(args, void *);
	unsigned long int addr;
	char buffer[16];
	char *hex = "0123456789abcdef";
	int i = 0, count = 0;

	if (p == NULL)
	{
		char *s = "(nil)";
		while (s[count])
			_putchar(s[count++]);
		return (count);
	}

	addr = (unsigned long int)p;
	count += _putchar('0');
	count += _putchar('x');

	if (addr == 0)
	{
		count += _putchar('0');
		return (count);
	}

	while (addr > 0)
	{
		buffer[i++] = hex[addr % 16];
		addr /= 16;
	}

	for (i--; i >= 0; i--)
		count += _putchar(buffer[i]);

	return (count);
}
