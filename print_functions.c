#include "main.h"

int print_char(va_list args, int f, int w, int p, int l)
{
	int count = 0;
	char c = va_arg(args, int);
	(void)f; (void)p; (void)l;
	while (w > 1) { count += _putchar(' '); w--; }
	return (count + _putchar(c));
}

int print_string(va_list args, int f, int w, int p, int l)
{
	char *s = va_arg(args, char *);
	int i, len = 0, count = 0;
	(void)f; (void)l;

	if (!s) s = "(null)";
	while (s[len]) len++;
	if (p >= 0 && p < len) len = p;

	while (w > len) { count += _putchar(' '); w--; }
	for (i = 0; i < len; i++) count += _putchar(s[i]);
	return (count);
}

int print_percent(va_list args, int f, int w, int p, int l)
{
	(void)args; (void)f; (void)w; (void)p; (void)l;
	return (_putchar('%'));
}
