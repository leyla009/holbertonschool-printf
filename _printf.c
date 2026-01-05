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
    /* Move to next char to check for flags */
    while (format[i + 1] == '+' || format[i + 1] == ' ' || format[i + 1] == '#')
    {
        i++;
        if (format[i] == '+') flags |= 1;
        if (format[i] == ' ') flags |= 2;
        if (format[i] == '#') flags |= 4;
    }

    /* If the flag was a space and the NEXT char is NOT a specifier */
    if (format[i] == ' ' && !format[i + 1])
        return (-1);

    i++; /* Move to the character that SHOULD be a specifier */
    
    for (j = 0; types[j].spec != 0; j++)
    {
        if (format[i] == types[j].spec)
        {
            count += types[j].f(args, flags);
            break;
        }
    }
    
    if (types[j].spec == 0) /* No valid specifier found */
    {
        if (format[i] == '\0')
            return (-1);
        
        /* If it was just "% ", we need to print the '%' and the ' ' */
        count += _putchar('%');
        if (format[i - 1] == ' ')
            count += _putchar(' ');
        
        if (format[i] != ' ')
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
