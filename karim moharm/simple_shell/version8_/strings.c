#include "shell.h"

/**
 * _putchar - print char
 * @c: char
 * Return: on success 1, on error -1
 */

int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
 * _puts - print string
 * @str: string to be printed
 * Return: number of char in the string
*/

int _puts(char *str)
{
	int i = 0;
	int count = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
		count++;
	}
	return (count);
}

/**
 * _strcmp - Compares two strings.
 * @str1: The first string to be compared.
 * @str2: The second string to be compared.
 *
 * Return: 1 if str1 > str2, 0 if str1 = str2 and -1 if str1 < str2
 */

int _strcmp(const char *str1, const char *str2)
{
	while (*str1 == *str2 && *str1 && *str2)
	{
		str1++;
		str2++;
	}
	if (*str1 > *str2)
		return (1);
	else if (*str1 < *str2)
		return (-1);

	return (0);
}

/**
 * _strlen - Returns the length of a string.
 * @s: A pointer to the characters string.
 *
 * Return: The length of the character string.
 */

int _strlen(const char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}
