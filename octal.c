#include "main.h"
#include "stdio.h"
#include "stdlib.h"

/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: Argument list
 * @buffer: array for buffer
 * @f:  Calc flags
 * @w: get the width
 * @p: Precision
 * @sz: Size
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[], int f, int w, int p, int sz)
{

	int i = SIZE_BUFFER - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(w);

	num = convert_size_unsgnd(num, sz);

	if (num == 0)
		buffer[i--] = '0';

	buffer[SIZE_BUFFER - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (f & HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, f, w, p, sz));
}
