#include "main.h"
#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>

/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buf: buf array to handle print.
 * @f: Calculates active f
 * @w: get w.
 * @p: p specification
 * @sz: sz specifier
 * Return: 1 or 2;
 */

int handle_print(const char *fmt, int *ind, va_list list, char buf[], int f,
int w, int p, int sz)
{
	int i, len = 0, fmt_chrs = -1;
	fmt_t types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadec},
		{'X', print_hexa_up}, {'p', print_pointer}, {'S', non_printable},
		{'r', print_reverse}, {'R', print_rot13str}, {'\0', NULL}
	};
	for (i = 0; types[i].fmt != '\0'; i++)
		if (fmt[*ind] == types[i].fmt)
			return (types[i].fn(list, buf, f, w, p, sz));

	if (types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			len += write(1, " ", 1);
		else if (w)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		len += write(1, &fmt[*ind], 1);
		return (len);
	}
	return (fmt_chrs);
}

