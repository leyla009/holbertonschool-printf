#include "main.h"

/**
 * _printf - custom printf function
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, j, count = 0;
    spec_t specs[] = {
        {'c', print_char}, {'s', print_string}, {'%', print_percent},
        {'d', print_int}, {'i', print_int}, {0, NULL}
    };

    if (!format || (format[0] == '%' && !format[1]))
        return (-1);

    va_start(args, format);
    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            for (j = 0; specs[j].spec; j++)
            {
                if (format[i] == specs[j].spec)
                {
                    count += specs[j].f(args);
                    break;
                }
            }
            if (!specs[j].spec) /* No match found */
            {
                write(1, &format[i - 1], 1);
                write(1, &format[i], 1);
                count += 2;
            }
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
