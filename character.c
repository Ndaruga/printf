#include "main.h"
#include "stdarg.h"
#include "stdlib.h" /* malloc */

/**
 * print_c - handle function for %c
 * 
 * @param list 
 * Return: char* 
 */
char *print_c(va_list list)
{
	char *s;
	s = malloc(sizeof(char) * 2);
	s[0] = va_arg(list, int);
	s[1] = '\0';
	return (s);
}