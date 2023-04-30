#include "main.h"
#include "stdlib.h"
#include "stdarg.h"

/**
 * _printf - custom Printf function
 * @format: format.
 * Return: fmted chars.
 */
int _printf(const char *format, ...)
{
	int i, fmted ,fmted_chars = 0;
	int f, w, p, sz, buffer_index = 0;
	va_list list;
	char buffer[SIZE_BUFFER];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_index++] = format[i];
			if (buffer_index == SIZE_BUFFER)
				print_buffer(buffer, &buffer_index);
			/* write(1, &format[i], 1);*/
			fmted_chars++;
		}
		else
		{
			print_buffer(buffer, &buffer_index);
			f = buff_flags(format, &i);
			w = buff_width(format, &i, list);
			p = buff_precision(format, &i, list);
			sz = SIZE_BUFFER(format, &i);
			++i;
			fmted = handle_print(format, &i, list, buffer,
				f, w, p, sz);
			if (fmted == -1)
				return (-1);
			fmted_chars += fmted;
		}
	}

	print_buffer(buffer, &buffer_index);

	va_end(list);

	return (fmted_chars);
}

/**
 * print_buffer - Print content of the buffer
 * @buffer: Array of chars
 * @buffer_index: Index  to add next char
 */
void print_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);

	*buffer_index = 0;
}

