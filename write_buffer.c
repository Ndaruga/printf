#include "main.h"
#include "stdarg.h"
#include "stdlib.h" /* malloc */
#include "unistd.h"

/**
 * write_buffer - prints buffer, then frees it and frees va_list
 * @buffer: buffer holding print-ables
 * @len: length of print-able string
 * @list: va_list
 */
void write_buffer(char *buffer, int len, va_list list)
{
	char *buff;

	buff = realloc(buffer, len); /* realloc to correct size */
	write(1, buff, len); /* print */

	free(buff);
	va_end(list);
}
