#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j, count = 0;
	spec_t types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'d', print_int}, {'i', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal},
		{'x', print_hex_low}, {'X', print_hex_upp},
		{'S', print_S}, {0, NULL}
	};

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			for (j = 0; types[j].spec != 0; j++)
			{
				if (format[i] == types[j].spec)
				{
					count += types[j].f(args);
					break;
				}
			}
			if (types[j].spec == 0)
			{
				count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		else
			count += _putchar(format[i]);
		i++;
	}
	_putchar(-1); /* Final buffer flush */
	va_end(args);
	return (count);
}
