#include "unistd.h"
#include "main.h"

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
