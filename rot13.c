#include "main.h"
#include "stdio.h"
/**
 * rot13 - string encryption with rot13
 * @list: string to be changed
 * Return: new modified string
 */
char *rot13(va_list list)
{
	int i = 0;
	char *s;
	char *nw_str;

	s = va_arg(list, char *); /* store va_arg to only access argument once */

	nw_str = malloc(sizeof(char) * (_strlen(s) + 1));
	if (nw_str == NULL)
		return (NULL);

	/* iterate s and assign rot13 char to nw_str */
	while (s[i] != '\0')
	{
		if ((s[i] >= 'A' && s[i] <= 'M') || (s[i] >= 'a' && s[i] <= 'm'))
		{
			nw_str[i] = s[i] + 13;
		}
		else if ((s[i] >= 'N' && s[i] <= 'Z') || (s[i] >= 'n' && s[i] <= 'z'))
		{
			nw_str[i] = s[i] - 13;
		}
		else
			(nw_str[i] = s[i]);
		i++;
	}
	nw_str[i] = '\0';

	return (nw_str);
}
