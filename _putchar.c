#include "main.h"

/**
 * _printf - custom printf function
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, j, printed_chars = 0;
	va_list args;
	spec_t func_list[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'d', print_int}, {'i', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal},
		{'x', print_hex_low}, {'X', print_hex_upp}, {'\0', NULL}
	};

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++; /* Move to specifier */
			for (j = 0; func_list[j].spec != '\0'; j++)
			{
				if (format[i] == func_list[j].spec)
				{
					printed_chars += func_list[j].f(args);
					break;
				}
			}
			if (func_list[j].spec == '\0') /* No match found */
			{
				printed_chars += _putchar('%');
				printed_chars += _putchar(format[i]);
			}
		}
		else
			printed_chars += _putchar(format[i]);
		i++;
	}
	va_end(args);
	return (printed_chars);
}
