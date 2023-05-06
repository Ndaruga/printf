#include "main.h"
#include "stdio.h"
#include "stdlib.h"

/**
 * print_int - Print int
 * @types: Argument list
 * @buffer: array for buffer
 * @f:  Calc flags
 * @w: get the width.
 * @p: Precision
 * @sz: Size
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int f, int w, int p, int sz)
{
	int i = SIZE_BUFFER - 2;
	int negtv = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, sz);

	if (n == 0)
		buffer[i--] = '0';

	buffer[SIZE_BUFFER - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		negtv = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(negtv, i, buffer, f, w, p, sz));
}


/**
 * print_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: array for buffer
 * @f:  Calc flags
 * @w: get the width
 * @p: Precision
 * @sz: Size
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[], int f, int w, int p, int sz)
{
	int i = SIZE_BUFFER - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, sz);

	if (num == 0)
		buffer[i--] = '0';

	buffer[SIZE_BUFFER - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, f, w, p, sz));
}
