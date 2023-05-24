#include "main.h"

/**
 * _strcat - concatenate two strings
 * @dest: pointer to new string
 * @src: pointer to source string
 * Return: new string
 */
char *_strcat(char *dest, char *src)
{
	int len = _strlen(dest);
	int i;

	for (i = 0; *(src + i) != '\0'; i++)
		*(dest + len + i) = *(src + i);

	*(dest + len + i) = '\0';

	return (dest);
}
