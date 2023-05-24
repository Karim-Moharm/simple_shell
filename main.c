#include "main.h"

/**
 * main - Entry point
 * Return: 0 when success
 */
int main(void)
{
	char *command = NULL;
	char **av = NULL;

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
		av = split_string(command, " \t\n");
		if (av[0] == NULL)
		{
			free_2D(av);
			break;
		}
		execute_shell(command);
		free(command);
	}
	free(command);

	return (0);
}
