#ifndef _MAIN_H_
#define _MAIN_H_

int _printf(const char *format, ...);

char *_strcpy(char *dest, char *src);

int _strlen(char *s);

int check_buffer_overflow(char *buffer, int len);

char *create_buffer(void);

#endif
