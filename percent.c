#include "main.h"
#include "stdarg.h" /* va list */
#include "stdlib.h"
#include <unistd.h>

/**
 * print_percent - Prints a percent sign
 * @types: Argument list
 * @buffer: array for buffer
 * @f:  Calc flags
 * @w: get the width.
 * @p: Precision
 * @sz: Size
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],	int f, int w, int p, int sz)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(sz);
	return (write(1, "%%", 1));
}
