#include "main.h"
#include "stdio.h"
#include "stdlib.h"


/**
 * itob - change integer to binary
 * @list: integer to change
 * Return: string with binary
 */

char *itob(va_list list)
{
	int h = 0, twos = 1;
	int i, m;
	char *s;

	m = va_arg(list, int);
	i = m;

	/* malloc up to max int in binary */
	s = malloc(sizeof(char) * 33);
	if (s == NULL)
		return (NULL);

	/* account for negative numbers with '1' at index 0 */
	if (m < 0)
	{
		s[0] = 1 + '0';
		h++;
		m *= -1;
		i *= -1;
	}

	/* find biggest power of 2 it's divisible by */
	while (m > 1)
	{
		m /= 2;
		twos *= 2;
	}

	/* divide down and store binary num */
	while (twos > 0)
	{
		s[h++] = (i / twos + '0');
		i %= twos;
		twos /= 2;
	}
	s[h] = '\0';

	return (s);
}
