#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j, count = 0, flags, width, precision, length;
	spec_t types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'d', print_int}, {'i', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hex_low},
		{'X', print_hex_upp}, {'S', print_S}, {'p', print_pointer}, {0, NULL}
	};

	if (!format || (format[0] == '%' && !format[1])) return (-1);
	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			flags = 0; width = 0; precision = -1; length = 0;
			while (format[i + 1] == '+' || format[i + 1] == ' ' || 
			       format[i + 1] == '#' || format[i + 1] == '0' || format[i + 1] == '-')
			{
				i++;
				if (format[i] == '+') flags |= 1;      /* + */
				else if (format[i] == ' ') flags |= 2; /* space */
				else if (format[i] == '#') flags |= 4; /* # */
				else if (format[i] == '0') flags |= 8; /* 0 */
				else if (format[i] == '-') flags |= 16;/* - (Left Align) */
			}
			/* Width, Precision, Length parsing logic remains the same */
			if (format[i + 1] == '*') { width = va_arg(args, int); i++; }
			else while (format[i + 1] >= '0' && format[i + 1] <= '9')
				width = (width * 10) + (format[++i] - '0');
			if (format[i + 1] == '.') {
				precision = 0; i++;
				if (format[i + 1] == '*') { precision = va_arg(args, int); i++; }
				else while (format[i + 1] >= '0' && format[i + 1] <= '9')
					precision = (precision * 10) + (format[++i] - '0');
			}
			if (format[i+1] == 'l') { length = 1; i++; }
			else if (format[i+1] == 'h') { length = 2; i++; }
			i++;
			for (j = 0; types[j].spec; j++)
				if (format[i] == types[j].spec)
				{
					count += types[j].f(args, flags, width, precision, length);
					break;
				}
			if (!types[j].spec) {
				count += _putchar('%');
				if (format[i]) count += _putchar(format[i]);
			}
		} else count += _putchar(format[i]);
	}
	_putchar(-1); va_end(args);
	return (count);
}
