#include "main.h"
#include "stdarg.h" /* va list */
#include "stdlib.h"

/**
 * print_c - handle function for %s
 * 
 * @param list 
 * Return char* 
 */

char *print_s(va_list list)
{
	char *s;
	char *p;
	int strln;

	s = va_arg(list, char *);
	if (s == NULL)
		s = "(null)";

	strln = _strlen(s);

	p = malloc(sizeof(char) * strln + 1);
	if (p == NULL)
		return (NULL);

	return (_strcpy(p, s));
}
