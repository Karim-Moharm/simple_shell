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
		if (isatty(STDIN_FILENO))
		{
			print_string("$ ");
		}
		command = get_command();
		if (_strcmp("\n", command) == 0)
		{
			break;
		}
		if (_strcmp("exit\n", command) == 0 || command == NULL)
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
