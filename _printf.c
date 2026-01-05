#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j, count = 0, flags;
	spec_t types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'d', print_int}, {'i', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hex_low},
		{'X', print_hex_upp}, {'S', print_S}, {'p', print_pointer}, {0, NULL}
	};

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			flags = 0;
			while (format[i + 1] == '+' || format[i + 1] == ' ' || format[i + 1] == '#')
			{
				i++;
				if (format[i] == '+') flags |= 1;
				if (format[i] == ' ') flags |= 2;
				if (format[i] == '#') flags |= 4;
			}
			i++;
			for (j = 0; types[j].spec != 0; j++)
			{
				if (format[i] == types[j].spec)
				{
					count += types[j].f(args, flags);
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
	}
	_putchar(-1);
	va_end(args);
	return (count);
}
