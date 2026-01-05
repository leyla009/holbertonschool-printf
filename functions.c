#include "main.h"

/**
 * print_char - Prints a character
 * @args: list of arguments
 * Return: 1 (number of chars printed)
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_string - Prints a string
 * @args: list of arguments
 * Return: number of chars printed
 */
int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int i = 0;

	if (!s)
		s = "(null)";

	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

/**
 * print_percent - Prints a percent sign
 * @args: list of arguments (unused)
 * Return: 1
 */
int print_percent(va_list args)
{
	(void)args;
	write(1, "%", 1);
	return (1);
}
