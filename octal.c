#include "main.h"
#include "stdio.h"
#include "stdlib.h"


/**
 * itoOctal - convert int to octal
 * @list: int to convert
 * Return: string with octal
 */

char *itoOctal(va_list list)
{
	int h = 0, eights = 1;
	int i, m;
	char *s;

	m = va_arg(list, int);
	i = m;

	s = malloc(sizeof(char) * 12); /* malloc up to max int in octal*/
	if (s == NULL)
		return (NULL);

	if (m < 0)
	{
		s[0] = 1 + '0';
		h++;
		m *= -1;
		i *= -1;
	}

	/* find largest power of 8 it's divisible by */
	while (m > 1)
	{
		m /= 8;
		eights *= 8;
	}

	/* divide and store octal num */
	while (eights > 0)
	{
		s[h++] = (i / eights + '0');
		i %= eights;
		eights /= 8;
	}
	s[h] = '\0';

	return (s);
}
