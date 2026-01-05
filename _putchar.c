#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to a static buffer
 * @c: The character to print. If -1, flushes the buffer.
 * Return: 1
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
	{
		buffer[i] = c;
		i++;
	}

	return (1);
}
