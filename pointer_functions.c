#include "main.h"

/**
 * print_pointer - Prints an address in hex format
 * @args: va_list of arguments
 * @f: flags
 * @w: width
 * @precision: precision
 * @l: length modifier
 * Return: Number of characters printed
 */
int print_pointer(va_list args, int f, int w, int precision, int l)
{
	void *addr = va_arg(args, void *);
	unsigned long int ptr_val;
	char *hex = "0123456789abcdef";
	char buffer[20];
	int i = 0, count = 0, len = 0;
	char *nil = "(nil)";

	(void)precision; (void)l;

	if (!addr)
	{
		while (nil[len]) len++;
		if (!(f & 16)) /* Right align padding */
			while (w > len) { count += _putchar(' '); w--; }
		for (i = 0; nil[i]; i++) count += _putchar(nil[i]);
		if (f & 16) /* Left align padding (-) */
			while (w > len) { count += _putchar(' '); w--; }
		return (count);
	}

	ptr_val = (unsigned long int)addr;
	/* Convert address to hex string in buffer */
	do {
		buffer[i++] = hex[ptr_val % 16];
		ptr_val /= 16;
	} while (ptr_val > 0);

	len = i + 2; /* +2 for '0x' */

	/* Right Alignment Padding */
	if (!(f & 16))
	{
		while (w > len)
		{
			count += _putchar(' ');
			w--;
		}
	}

	/* Print prefix and hex address */
	count += _putchar('0');
	count += _putchar('x');
	for (i--; i >= 0; i--)
		count += _putchar(buffer[i]);

	/* Left Alignment Padding (-) */
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
