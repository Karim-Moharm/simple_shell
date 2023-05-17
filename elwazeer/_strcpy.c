#include "main.h"

/**
 * _strcpy - copy string
 * @dest: new copy
 * @src: string that want to copy
 * Return: pointer to a copy string
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; *(src + i) != '\0'; i++)
	{
		*(dest + i) = *(src + i);
	}
	*(dest + i) = '\0';

	return (dest);
}
