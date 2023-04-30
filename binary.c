#include "main.h"
#include "stdio.h"
#include "stdlib.h"

/**
 * print_binary - Prints an unsigned number
 * @types: Argument list
 * @buffer: array for buffer
 * @f:  Calc flags
 * @w: get the width.
 * @p: Precision
 * @sz: Size
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[], int f, int w, int p, int sz)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int cnt;

	UNUSED(buffer);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(sz);

	n = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, cnt = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			cnt++;
		}
	}
	return (cnt);
}

