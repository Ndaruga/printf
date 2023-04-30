#include "main.h"
#include "stdarg.h"
#include "stdlib.h" /* malloc */
#include "unistd.h"

#include "main.h"

/**
 * handle_write_char - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags.
 * @w: get w.
 * @p: p specifier
 * @sz: sz specifier
 *
 * Return: Number of chars printed.
 */
int write_char(char c, char buffer[], int f, int w, int p, int sz)
{
	int i = 0;
	char space = ' ';

	UNUSED(p);
	UNUSED(sz);

	if (f & ZERO)
		space = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (w > 1)
	{
		buffer[SIZE_BUFFER - 1] = '\0';
		for (i = 0; i < w - 1; i++)
			buffer[SIZE_BUFFER - i - 2] = space;

		if (f & MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[SIZE_BUFFER - i - 1], w - 1));
		else
			return (write(1, &buffer[SIZE_BUFFER - i - 1], w - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * write_number - Prints a string
 * @is_negative: Lista of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width.
 * @p: p specifier
 * @sz: sz specifier
 * Return: Number of chars printed.
 */

int write_number(int is_negative, int ind, char buffer[], int f, int w,
int p, int sz)
{
	int len = SIZE_BUFFER - ind - 1;
	char space = ' ', ex_chh = 0;

	UNUSED(sz);

	if ((f & ZERO) && !(f & MINUS))
		space = '0';
	if (is_negative)
		ex_chh = '-';
	else if (f & PLUS)
		ex_chh = '+';
	else if (f & SPACE)
		ex_chh = ' ';

	return (write_num(ind, buffer, f, w, p,
		len, space, ex_chh));
}

/**
 * write_num - Write a number using a buffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @f: Flags
 * @w: width
 * @prec: p specifier
 * @len: Number len
 * @space: Pading char
 * @ex_ch: Extra char
 *
 * Return: Number of printed chars.
 */
int write_num(int ind, char buffer[],
	int f, int w, int prec,
	int len, char space, char ex_ch)
{
	int i, space_start = 1;

	if (prec == 0 && ind == SIZE_BUFFER - 2 && buffer[ind] == '0' && w == 0)
		return (0);
	if (prec == 0 && ind == SIZE_BUFFER - 2 && buffer[ind] == '0')
		buffer[ind] = space = ' ';
	if (prec > 0 && prec < len)
		space = ' ';
	while (prec > len)
		buffer[--ind] = '0', len++;
	if (ex_ch != 0)
		len++;
	if (w > len)
	{
		for (i = 1; i < w - len + 1; i++)
			buffer[i] = space;
		buffer[i] = '\0';
		if (f & MINUS && space == ' ')
		{
			if (ex_ch)
				buffer[--ind] = ex_ch;
			return (write(1, &buffer[ind], len) + write(1, &buffer[1], i - 1));
		}
		else if (!(f & MINUS) && space == ' ')
		{
			if (ex_ch)
				buffer[--ind] = ex_ch;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], len));
		}
		else if (!(f & MINUS) && space == '0')
		{
			if (ex_ch)
				buffer[--space_start] = ex_ch;
			return (write(1, &buffer[space_start], i - space_start) +
				write(1, &buffer[ind], len - (1 - space_start)));
		}
	}
	if (ex_ch)
		buffer[--ind] = ex_ch;
	return (write(1, &buffer[ind], len));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @f: Flags specifiers
 * @w: Width specifier
 * @p: p specifier
 * @sz: sz specifier
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int is_negative, int ind, char buffer[], int f, int w,
int p, int sz)
{
	int len = SIZE_BUFFER - ind - 1, i = 0;
	char space = ' ';

	UNUSED(is_negative);
	UNUSED(sz);

	if (p == 0 && ind == SIZE_BUFFER - 2 && buffer[ind] == '0')
		return (0);

	if (p > 0 && p < len)
		space = ' ';

	while (p > len)
	{
		buffer[--ind] = '0';
		len++;
	}

	if ((f & ZERO) && !(f & MINUS))
		space = '0';

	if (w > len)
	{
		for (i = 0; i < w - len; i++)
			buffer[i] = space;

		buffer[i] = '\0';

		if (f & MINUS)
		{
			return (write(1, &buffer[ind], len) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], len));
		}
	}

	return (write(1, &buffer[ind], len));
}

/**
 * write_pointer - Write a memory address
 * @buffer: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @len: Length of number
 * @w: Width specifier
 * @f: Flags specifier
 * @space: Char representing the spaceing
 * @ex_ch: Char representing extra char
 * @space_start: Index at which spaceing should start
 *
 * Return: Number of written chars.
 */
int write_pointer(char buffer[], int ind, int len, int w, int f, char space,
char ex_ch, int space_start)
{
	int i;

	if (w > len)
	{
		for (i = 3; i < w - len + 3; i++)
			buffer[i] = space;
		buffer[i] = '\0';
		if (f & MINUS && space == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (ex_ch)
				buffer[--ind] = ex_ch;
			return (write(1, &buffer[ind], len) + write(1, &buffer[3], i - 3));
		}
		else if (!(f & MINUS) && space == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (ex_ch)
				buffer[--ind] = ex_ch;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], len));
		}
		else if (!(f & MINUS) && space == '0')
		{
			if (ex_ch)
				buffer[--space_start] = ex_ch;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[space_start], i - space_start) +
				write(1, &buffer[ind], len - (1 - space_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (ex_ch)
		buffer[--ind] = ex_ch;
	return (write(1, &buffer[ind], SIZE_BUFFER - ind - 1));
}
