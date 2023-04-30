#include "main.h"
#include "stdarg.h" /* va list */
#include "stdlib.h"

/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: array for buffer
 * @f:  Calc flags
 * @w: get the width.
 * @p: Precision
 * @sz: Size
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
	int f, int w, int p, int sz)
{
	int len = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(sz);
	if (str == NULL)
	{
		str = "(null)";
		if (p >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (p >= 0 && p < len)
		len = p;

	if (w > len)
	{
		if (f & MINUS)
		{
			write(1, &str[0], len);
			for (i = w - len; i > 0; i--)
				write(1, " ", 1);
			return (w);
		}
		else
		{
			for (i = w - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (w);
		}
	}

	return (write(1, str, len));
}
