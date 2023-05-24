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

/**
 * _strcmp - compare between two string
 * @str1: pointer to 1st string
 * @str2: pointer to 2nd string
 * Return: +ve or 0 or -ve
 */
int _strcmp(char *str1, char *str2)
{
	int i, r;

	for (i = 0; *(str1 + i) != '\0' || *(str2 + i) != '\0'; i++)
	{
		r = *(str1 + i) - *(str2 + i);
		if (r != 0)
			break;
	}
	return (r);
}

/**
 * _strncmp - compare between two string
 * @str1: pointer to 1st string
 * @str2: pointer to 2nd string
 * @n: number of charcter that will compare
 * Return: +ve or 0 or -ve
 */
int _strncmp(char *str1, char *str2, unsigned int n)
{
	unsigned int i;
	int r;

	for (i = 0; (*(str1 + i) != '\0' || *(str2 + i) != '\0') && (i < n); i++)
	{
		r = *(str1 + i) - *(str2 + i);
		if (r != 0)
			break;
	}
	return (r);
}

/**
 * _strlen - calc number of string
 * @str: pointer to string
 * Return: Number of string
 */
int _strlen(char *str)
{
	int len;

	for (len = 0; *(str + len) != '\0'; len++)
		;
	return (len);
}

/**
 * _strdup - create a duplicate (copy) of a string.
 * @str: pointer to string
 * Return: duplicate copy
 */
char *_strdup(char *str)
{
	char *dup = NULL;

	if (str == NULL)
		return (NULL);

	dup = (char *)malloc(_strlen(str) + 1);
	if (dup == NULL)
		return (NULL);

	_strcpy(dup, str);
	return (dup);
}
