#include "main.h"

/**
 * print_pointer - Prints the value of a pointer variable
 * @args: va_list containing the pointer to print
 * @f: flags
 * @w: width
 * @precision: precision (unused for pointer but required for signature)
 * @l: length modifier
 * Return: Number of characters printed
 */
int print_pointer(va_list args, int f, int w, int precision, int l)
{
	void *ptr = va_arg(args, void *);
	unsigned long int addr;
	char buffer[16];
	char *hex = "0123456789abcdef";
	int i = 0, count = 0;
	
	(void)f; 
	(void)w; 
	(void)precision; 
	(void)l;

	if (!p)
	{
		char *s = "(nil)";
		while (s[count])
			_putchar(s[count++]);
		return (count);
	}

	addr = (unsigned long int)ptr;
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
