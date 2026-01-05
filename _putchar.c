#include "main.h"

/**
 * _putchar - writes the character c to a static buffer
 * @c: The character to print
 * * Return: 1 (always, as it buffers)
 * If c is -1, it flushes the buffer.
 */
int _putchar(char c)
{
	static char buffer[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, buffer, i);
		i = 0;
	}
	if (c != -1)
		buffer[i++] = c;

	return (1);
}
