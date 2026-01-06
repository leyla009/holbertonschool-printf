#include <unistd.h>

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
		buffer[i++] = c;
		return (1);
	}
	return (0);
}
