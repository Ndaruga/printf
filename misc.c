#include "main.h"
#include "stdarg.h" /* va list */
#include "stdlib.h"
#include <unistd.h>

/**
 * printable - Evaluates if a char is printable
 * @c: Char to be evaluated.
 * Return: 1 if c is printable, 0 otherwise
 */
int printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa - Append asci in hexadecimal
 * @buf: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa(char ascii_code, char buf[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buf[i++] = '\\';
	buf[i++] = 'x';
	buf[i++] = map_to[ascii_code / 16];
	buf[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 * Return: 1 if c is a digit, 0 otherwise
 */
int digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts a number to the specified size
 * @num: Number to be casted.
 * @sz: Number indicating the type to be casted.
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int sz)
{
	if (sz == 2)
		return (num);
	else if (sz == 1)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @num: Number to be casted
 * @sz: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int sz)
{
	if (sz == 2)
		return (num);
	else if (sz == 1)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

