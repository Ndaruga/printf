#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#define MINUS 1
#define PLUS 2
#define ZERO 4
#define HASH 8
#define SPACE 16
#define UNUSED(x) (void)(x)
#define SIZE_BUFFER 1024


int _printf(const char *format, ...);
int _strlen(char *s);

int print_char(va_list types, char buffer[], int f, int w, int p, int sz);
int print_string(va_list types, char buffer[], int f, int w, int p, int sz);
int print_percent(va_list types, char buffer[], int f, int w, int p, int sz);
int print_int(va_list types, char buffer[], int f, int w, int p, int sz);
int print_binary(va_list types, char buffer[], int f, int w, int p, int sz);
int print_unsigned(va_list types, char buffer[], int f, int w, int p, int sz);
int print_octal(va_list types, char buffer[], int f, int w, int p, int sz);
int print_hexadec(va_list types, char buffer[], int f, int w, int p, int sz);
int print_hexa_up(va_list types, char buffer[], int f, int w, int p, int sz);
int print_hexa(va_list types, char map_to[], char buffer[], int f,
char flag_ch, int w, int p, int sz);

int buff_flags(const char *format, int *i);
int buff_width(const char *format, int *i, va_list list);
int buff_precision(const char *format, int *i, va_list list);
int buff_size(const char *format, int *i);

void print_buffer(char buffer[], int *buffer_index);

int print_reverse(va_list types, char buffer[],	int f, int w, int p, int sz);
int print_rot13str(va_list types, char buffer[], int f, int w, int p, int sz);
int print_octal(va_list types, char buffer[], int f, int w, int p, int sz);
int print_pointer(va_list types, char buffer[],	int f, int w, int p, int sz);
int non_printable(va_list types, char buffer[], int f, int w, int p, int sz);

int write_char(char c, char buffer[], int f, int w, int p, int sz);
int write_number(int is_positive, int ind, char buffer[], int f, int w,
int p, int sz);
int write_num(int ind, char bff[], int f, int w, int p,	int length,
char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length, int w, int f,
char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind, char buffer[], int f,
int w, int p, int sz);


int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_size_number(long int num, int sz);
long int convert_size_unsgnd(unsigned long int num, int sz);



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
