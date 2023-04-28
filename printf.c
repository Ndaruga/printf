#include "main.h"
#include "stdlib.h"
#include "stdarg.h"

/**
 * process_text_format - processing the text format
 * of the input string and copying it into the buffer.
 *
 * @format: text format
 * @buffer: buffer
 * @len: len
 * @total_len: len of str
 * Return - None
 */

void process_text_format(char *format, char *buffer, int *len, int *total_len)
{
	while (*format != '\0')
	{
		if (*format != '%')
		{
			*len = check_buffer_overflow(buffer, *len);
			buffer[(*len)++] = *format++;
			(*total_len)++;
		}
		else
		{
			format++;
			break;
		}
	}
}

/**
 * valid_specifier - processing a valid format specifier
 *  and copying its string representation into the buffer.
 *
 * @format: text format
 * @buffer: buffer
 * @len: len
 * @total_len: len of str
 * @list: lis
 * Return - None
 */


void valid_specifier(char *format, char *buffer,
int *len, int *total_len, va_list list)
{
	char *str, *(*f)(va_list);

	f = get_func(*format);
	if (f != NULL)
	{
		str = f(list);
		if (str != NULL)
		{
			int j = 0;

			while (str[j] != '\0')
			{
				*len = check_buffer_overflow(buffer, *len);
				buffer[(*len)++] = str[j++];
				(*total_len)++;
			}
			free(str);
		}
	}
}

/**
 * invalid_specifier - processing an invalid format specifier
 * and copying it into the buffer as a regular character.
 *
 * @format: text format
 * @buffer: buffer
 * @len: len
 * @total_len: len of str
 * Return - None
 */

void invalid_specifier(char *format, char *buffer, int *len, int *total_len)
{
	*len = check_buffer_overflow(buffer, *len);
	buffer[(*len)++] = '%';
	(*total_len)++;
	buffer[(*len)++] = *format;
	(*total_len)++;
}

/**
 * _printf - custom printf fn
 *
 * @format: Initial string
 * @...:
 * Return: string with characters and format sprcifiers expanded
 */

int _printf(const char *format, ...)
{
	int len = 0, total_len = 0;
	char *buffer = create_buffer();
	va_list list;

	va_start(list, format);
	if ((buffer == NULL) || (format == NULL))
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				va_end(list);
				free(buffer);
				return (-1);
			}
			else if (*format == '%')
			{
				len = check_buffer_overflow(buffer, len);
				buffer[len++] = *format++;
				total_len++;
			}
			else
			{
				process_text_format((char *)format - 1, buffer, &len, &total_len);
				valid_specifier(format, buffer, &len, &total_len, list);
				while (*format != '\0' && !is_valid_specifier(*format))
					invalid_specifier(format++, buffer, &len, &total_len);
			}
		}
		process_text_format((char *)format++, buffer, &len, &total_len);
	}

	write_buffer(buffer, len, list);
	va_end(list);
	free(buffer);
	return (total_len);
}
