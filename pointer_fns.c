#include "main.h"
#include "stdarg.h" /* va list */
#include "stdlib.h"
#include <unistd.h>

/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: array for buffer
 * @f:  Calc flags
 * @w: get the width
 * @p: Precision
 * @sz: Size
 * Return: Number of chars printed.
 */
int print_pointer(va_list types, char buffer[],	int f, int w, int p, int sz)
{
	char extra_c = 0, padd = ' ';
	int ind = SIZE_BUFFER - 2, len = 2, padd_start = 1; /* len=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(w);
	UNUSED(sz);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[SIZE_BUFFER - 1] = '\0';
	UNUSED(p);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		len++;
	}

	if ((f & ZERO) && !(f & MINUS))
		padd = '0';
	if (f & PLUS)
		extra_c = '+', len++;
	else if (f & SPACE)
		extra_c = ' ', len++;

	ind++;

	/*return (write(1, &buffer[i], SIZE_BUFFER - i - 1));*/
	return (write_pointer(buffer, ind, len,
		w, f, padd, extra_c, padd_start));
}

/**
 * non_printable - Prints ascii-codes in hexadecimal of non printable chars
 * @types: List of arguments
 * @buffer: Buffer array 
 * @f:  flags active 
 * @w:  w
 * @p: Precision
 * @sz: Size
 * Return: Number of chars printed
 */

int non_printable(va_list types, char buffer[], int f, int w, int p, int sz)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(sz);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}
