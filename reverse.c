#include "main.h"
#include "stdio.h"
#include "stdlib.h"

/**
 * print_reverse - Prints reverse string.
 * @types: Argument list
 * @buffer: array for buffer
 * @f:  Calc flags
 * @w: get the width
 * @p: Precision
 * @sz: Size
 * Return: Numbers of chars printed
 */

int print_reverse(va_list types, char buffer[],	int f, int w, int p, int sz)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(f);
	UNUSED(w);
	UNUSED(sz);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(p);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
