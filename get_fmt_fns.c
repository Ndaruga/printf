#include "main.h"
#include "stdarg.h"
#include "stdlib.h" /* malloc */


/**
 * get_func - returns required function
 * @i: identifier for functional format
 * Return: Pointer to required function
 */
char* (*get_func(char i))(va_list)
{
	int k = 0;

	print_fn keys[] = {
		{'c', print_c},
		{'s', print_s},
		{'d', print_d},
		{'i', print_d},
		{'b', itob},
		{'R', rot13},
		{'r', rev_string},
		{'o', itoOctal},
		{'\0', NULL}
	};

	while (keys[k].id != '\0')
	{
		if (keys[k].id == i)
			return (keys[k].func);
		k++;
	}
	return (NULL);
}
