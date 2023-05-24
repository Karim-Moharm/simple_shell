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
		if (_strcmp("exit\n", command) == 0)
		{
			free(command);
			exit(EXIT_SUCCESS);
		}
		av = split_string(command, " \n\t");
		if (av[0] == NULL)
		{
			break;
		}
		execute_shell(command, av);
		free(command);
		free_2D(av);
	}
	free_2D(av);
	free(command);

	return (0);
}
