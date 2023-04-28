#include "main.h"
#include "stdlib.h"
#include "stdarg.h"

/**
 * _printf - custom printf fn
 *
 * @format: Initial string
 * @...:
 * Return: string with characters and format sprcifiers expanded
 */

int _printf(const char *format, ...)
{
	int len = 0, total_len = 0, i = 0, j = 0;
	va_list list;
	char *buffer, *str;
	char* (*f)(va_list);

	if (format == NULL)
		return (-1);

	buffer = create_buffer();
	if (buffer == NULL)
		return (-1);

	va_start(list, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%') /* copy format into buffer until you encounter '%' */
		{
			len = check_buffer_overflow(buffer, len);
			buffer[len++] = format[i++];
			total_len++;
		}
		else /* if %, ... */
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(list);
				free(buffer);
				return (-1);
			}
			if (format[i] == '%')
			{
				len = check_buffer_overflow(buffer, len);
				buffer[len++] = format[i];
				total_len++;
			}
			else
			{
				f = get_func(format[i]); /* grab function */
				if (f == NULL)  /* handle fake id */
				{
					len = check_buffer_overflow(buffer, len);
					buffer[len++] = '%'; total_len++;
					buffer[len++] = format[i]; total_len++;
				}
				else /* return string, copy to buffer */
				{
					str = f(list);
					if (str == NULL)
					{
						va_end(list);
						free(buffer);
						return (-1);
					}
					if (format[i] == 'c' && str[0] == '\0')
					{
						len = check_buffer_overflow(buffer, len);
						buffer[len++] = '\0';
						total_len++;
					}
					j = 0;
					while (str[j] != '\0')
					{
						len = check_buffer_overflow(buffer, len);
						buffer[len++] = str[j];
						total_len++; j++;
					}
					free(str);
				}
			} i++;
		}
	}
	write_buffer(buffer, len, list);
	return (total_len);
}
