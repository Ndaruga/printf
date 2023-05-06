#include "main.h"
#include "stdarg.h"
#include "stdlib.h" /* malloc */

/**
 * print_char - Prints a char
 * @types: List of arguments
 * @buffer: array for buffer
 * @f:  Calc flags
 * @w: width
 * @p: Precision
 * @sz: Size
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[], int f, int w, int p, int sz)
{
	char c = va_arg(types, int);

	return (write_char(c, buffer, f, w, p, sz));
}
