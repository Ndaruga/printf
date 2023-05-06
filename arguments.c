#include "main.h"
#include "stdio.h"
#include "stdlib.h"

/**
 * buff_size - Calculates the sz to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: size.
 */

int buff_size(const char *format, int *i)
{
	int indx = *i + 1;
	int sz = 0;

	if (format[indx] == 'l')
		sz = 2;
	else if (format[indx] == 'h')
		sz = 1;

	if (sz == 0)
		*i = indx - 1;
	else
		*i = indx;

	return (sz);
}

/**
 * buff_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */

int buff_precision(const char *format, int *i, va_list list)
{
	int indx = *i + 1;
	int p = -1;

	if (format[indx] != '.')
		return (p);

	p = 0;

	for (indx += 1; format[indx] != '\0'; indx++)
	{
		if (digit(format[indx]))
		{
			p *= 10;
			p += format[indx] - '0';
		}
		else if (format[indx] == '*')
		{
			indx++;
			p = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = indx - 1;

	return (p);
}

/**
 * buff_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */

int buff_width(const char *format, int *i, va_list list)
{
	int indx;
	int w = 0;

	for (indx = *i + 1; format[indx] != '\0'; indx++)
	{
		if (digit(format[indx]))
		{
			w *= 10;
			w += format[indx] - '0';
		}
		else if (format[indx] == '*')
		{
			indx++;
			w = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = indx - 1;

	return (w);
}

/**
 * buff_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */

int buff_flags(const char *format, int *i)
{

	int j, indx;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {MINUS, PLUS, ZERO, HASH, SPACE, 0};

	for (indx = *i + 1; format[indx] != '\0'; indx++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[indx] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = indx - 1;

	return (flags);
}

