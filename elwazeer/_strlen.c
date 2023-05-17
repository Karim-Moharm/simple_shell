#include "main.h"

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
