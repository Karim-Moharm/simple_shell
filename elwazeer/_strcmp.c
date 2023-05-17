#include "main.h"

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
	return (r)
}
