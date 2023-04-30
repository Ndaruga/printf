#include "main.h"
#include "stdio.h"
#include "stdlib.h"

/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Argument list
 * @map_to: Array of values to map the number to
 * @buffer: array for buffer
 * @f:  Calculates active f
 * @flag_ch: Calculates active f
 * @w: get the width
 * @p: Precision
 * @sz: Size
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],	int f,
char flag_ch, int w, int p, int sz)
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
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (f & HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, f, w, p, sz));
}
