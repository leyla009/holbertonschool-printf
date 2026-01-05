#include "main.h"

/**
 * _printf - prints formatted output to stdout
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *p;

    if (!format)
        return (-1);

    va_start(args, format);

    for (p = format; *p; p++)
    {
        if (*p == '%')
        {
            p++; /* move to the next character */

            if (!*p) /* if % is the last character, do nothing */
                break;

            if (*p == 'c')
            {
                char c = (char)va_arg(args, int);
                write(1, &c, 1);
                count++;
            }
            else if (*p == 's')
            {
                char *s = va_arg(args, char *);
                if (!s)
                    s = "(null)";
                while (*s)
                {
                    write(1, s, 1);
                    s++;
                    count++;
                }
            }
            else if (*p == '%')
            {
                write(1, "%", 1);
                count++;
            }
            /* unknown specifiers are ignored completely */
        }
        else
        {
            write(1, p, 1);
            count++;
        }
    }

    va_end(args);
    return (count);
}

