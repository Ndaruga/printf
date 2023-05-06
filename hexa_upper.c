#include "main.h"
#include "stdio.h"
#include "stdlib.h"

/**
 * print_hexa_up - Prints an unsigned number in upper hexadecimal notation
 * @types: Argument list
 * @buffer: array for buffer
 * @f:  Calc flags
 * @w: get the width
 * @p: Precision
 * @sz: Size
 * Return: Number of chars printed
 */
int print_hexa_up(va_list types, char buffer[],	int f, int w, int p, int sz)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		f, 'X', w, p, sz));
}
