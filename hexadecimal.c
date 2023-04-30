#include "main.h"
#include "stdio.h"
#include "stdlib.h"

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Argument list
 * @buffer: array for buffer
 * @f:  Calc flags
 * @w: get the width
 * @p: Precision
 * @sz: Size
 * Return: Number of chars printed
 */
int print_hexadec(va_list types, char buffer[],	int f, int w, int p, int sz)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		f, 'x', w, p, sz));
}
