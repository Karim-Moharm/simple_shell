#include "main.h"

/**
 * main - Entry point
 * Return: 0 when success
 */
int main(void)
{
	char *command = NULL;

	while (1)
	{
		print_string("($) ");
		command = get_command();
		if (_strcmp("exit\n", command) == 0)
		{
			free(command);
			exit(EXIT_SUCCESS);
		}
		execute_shell(command);
		free(command);
	}
	free(command);
	return (0);
}
