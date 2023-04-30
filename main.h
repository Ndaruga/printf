#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#define MINUS 1
#define PLUS 2
#define ZERO 4
#define HASH 8
#define SPACE 16
#define UNUSED(x) (void)(x)
#define sz_BUFFER 1024


int _printf(const char *format, ...);

int print_char(va_list types, char buffer[], int f, int w, int p, int sz);
int print_string(va_list types, char buffer[], int f, int w, int p, int sz);
int print_percent(va_list types, char buffer[], int f, int w, int p, int sz);


int print_int(va_list types, char buffer[], int f, int w, int p, int sz);
int print_binary(va_list types, char buffer[], int f, int w, int p, int sz);
int print_unsigned(va_list types, char buffer[], int f, int w, int p, int sz);
int print_octal(va_list types, char buffer[], int f, int w, int p, int sz);
int print_hexadeci(va_list types, char buffer[], int f, int w, int p, int sz);
int print_hexa_up(va_list types, char buffer[], int f, int w, int p, int sz);
int print_hexa(va_list types, char map_to[], char buffer[], int f,
char flag_ch, int w, int p, int sz);


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */

typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int f, int w, int p, int sz);


/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

#endif
