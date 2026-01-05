#include "main.h"

/**
 * _putchar - writes the character c to a static buffer
 * @c: The character to print
 * * Return: 1
 */
int _putchar(char c)
{
    static char buffer[1024];
    static int i;

    /* If c is -1 or buffer is full, flush to stdout */
    if (c == -1 || i >= 1024)
    {
        write(1, buffer, i);
        i = 0;
    }

    if (c != -1)
    {
        buffer[i] = c;
        i++;
    }

    return (1);
}
