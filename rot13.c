#include "main.h"
#include "stdio.h"
#include <unistd.h>
#include "stdlib.h"

/**
 * print_rot13str - Print a string in rot13.
 * @types: Argument list
 * @buffer: array for buffer
 * @f:  Calc flags
 * @w: get the width
 * @p: Precision
 * @sz: Size
 * Return: Numbers of chars printed
 */

int print_rot13str(va_list types, char buffer[], int f, int w, int p, int sz)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(sz);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
