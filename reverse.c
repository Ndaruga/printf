#include "main.h"
#include "stdio.h"

/**
 * rev_string - reverses a string
 * @list: string to reverse
 * Return: reversed string
 */

char *rev_string(va_list list)
{
    char *rev_str;
	char *str;
	int i = 0, len, j;

	str = va_arg(list, char *);
	if (str == NULL)
		str = ")llun(";

	len = _strlen(str);

	rev_str = malloc(sizeof(char) * (len + 1));
	if (rev_str == NULL)
		return (NULL);

	for(j = (len - 1); j >= 0; j--)
	{
		rev_str[i++] = str[j];
	}
	rev_str[i] = '\0';

	return (rev_str);
}
