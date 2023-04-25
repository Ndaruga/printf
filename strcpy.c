#include "main.h"
#include "stdio.h"

/**
 * _strlen - returns the length of a string
 * @s: Characters to count
 * Return: count integer
 */

int _strlen(char *s)
{
	int count = 0;
	char i;

	for (i = *s; i != '\0'; i = *++s)
	{
		count++;
	}
	return (count);
}


/**
 * _strcpy - function to copy a string from src to dest
 * @dest: destination
 * @src: source
 * Return: characters in the destination
 */

char *_strcpy(char *dest, char *src)
{
	int n = _strlen(src);
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	if (i == n)
		dest[i] = '\0';

	return (dest);
}
