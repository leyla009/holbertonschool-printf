#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string containing literal text and specifiers
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j, count = 0;
	int flags, width, length;
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
			/* Reset modifiers for every specifier */
			flags = 0; width = 0; length = 0;

			/* 1. Parse Flags (+, ' ', #) */
			while (format[i + 1] == '+' || format[i + 1] == ' ' || format[i + 1] == '#')
			{
				i++;
				if (format[i] == '+') flags |= 1;
				else if (format[i] == ' ') flags |= 2;
				else if (format[i] == '#') flags |= 4;
			}

			/* 2. Parse Width (e.g., %6d or %*d) */
			if (format[i + 1] == '*')
			{
				width = va_arg(args, int);
				i++;
			}
			else
			{
				while (format[i + 1] >= '0' && format[i + 1] <= '9')
				{
					width = (width * 10) + (format[i + 1] - '0');
					i++;
				}
			}

			/* 3. Parse Length (l, h) */
			if (format[i + 1] == 'l') { length = 1; i++; }
			else if (format[i + 1] == 'h') { length = 2; i++; }

			/* 4. Match and Execute Specifier */
			i++;
			for (j = 0; types[j].spec != 0; j++)
			{
				if (format[i] == types[j].spec)
				{
					count += types[j].f(args, flags, width, length);
					break;
				}
			}
			if (types[j].spec == 0) /* No matching specifier found */
			{
				if (format[i] == '\0') return (-1);
				count += _putchar('%');
				/* Handle cases like "% " or "% +y" */
				if (format[i - 1] == ' ') count += _putchar(' ');
				if (format[i] != ' ') count += _putchar(format[i]);
			}
		}
		else
		{
			count += _putchar(format[i]);
		}
	}
	_putchar(-1); /* Final buffer flush for Task 5 */
	va_end(args);
	return (count);
}
