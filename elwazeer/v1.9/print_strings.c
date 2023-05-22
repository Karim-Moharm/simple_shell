#include "main.h"

/**
 * _putchar - write the character c to stdout
 * @c: The character to print
 *
 * Return: On Success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - print string
 * @str: pointer to string
 *
 * Return: return 1 On success
 * On error, return -1
 */
int _puts(char *str)
{
	size_t count = (size_t)_strlen(str);
	int new_line = '\n';

	if (write(1, str, count) == -1)
		return (-1);

	if (write(1, &new_line, 1) == -1)
		return (-1);

	return (1);
}

/**
 * print_string - print string
 * @str: pointer to string
 * Return: Number of string
 */
int print_string(char *str)
{
	int i;

	for (i = 0; *(str + i) != '\0'; i++)
		_putchar(*(str + i));

	return (i);
}
