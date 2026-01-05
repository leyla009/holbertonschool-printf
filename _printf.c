#include "main.h"

/**
 * handle_specifier - Matches a specifier with a function
 * @spec: The specifier character
 * @args: The arguments list
 * Return: Number of characters printed
 */
int handle_specifier(char spec, va_list args)
{
	spec_t specs[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{0, NULL}
	};
	int i = 0;

	while (specs[i].spec)
	{
		if (specs[i].spec == spec)
			return (specs[i].f(args));
		i++;
	}

	/* If no match is found, print the % and the unknown character */
	write(1, "%", 1);
	write(1, &spec, 1);
	return (2);
}

/**
 * _printf - custom printf function
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, i = 0;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				va_end(args);
				return (-1);
			}
			count += handle_specifier(format[i + 1], args);
			i++; /* skip the specifier character */
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
