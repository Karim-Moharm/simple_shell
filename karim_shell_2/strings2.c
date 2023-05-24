#include "shell.h"

/**
 * _strdup - duplicate the string to new mem location
 * @str: string to be duplicated
 * Return: the new string
*/

char *_strdup(const char *str)
{
	char *new_str;
	int i = 0;

	if (str == NULL)
		return (NULL);

	new_str = malloc(sizeof(char) * (_strlen(str) + 1));

	if (new_str == NULL)
		return (NULL);

	while (str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';

	return (new_str);
}

/**
 * _strcat - Concantenates two strings.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 *
 * Return: Pointer to destination string.
 */

char *_strcat(char *dest, const char *src)
{
	int len = 0;
	int i = 0;

	len = _strlen(dest);

	while (src[i] != '\0')
	{
		dest[len++] = src[i++];
	}
	dest[len] = '\0';

	return (dest);
}

/**
* _strncmp - compare two strings whit specific size
* @s1: first string
* @s2: second string
* @n: size
* Return: positive integer if s1 > s2
* negative is s1 < s2 , and 0 if equal
*/

int _strncmp(char *s1, const char *s2, int n)
{
	while (*s1 && *s2 && *s1 == *s2 && n)
	{
		s1++;
		s2++;
		n--;
	}

	if (n == 0)
		return (0);
	return (*s1 - *s2);
}
