#include "shell.h"
/**
 * _strncopy : copy n char
 * @dest: string argument
 * @src: string argument for src
 * @n: integer argument
 * Return: dest
 */
char *_strncopy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}
