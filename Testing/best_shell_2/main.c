#include "main.h"

/**
 * main - Entry point
 * @ac: number
 * @av: pointer to content
 * @env: pointer to pointer
 * Return: 0 when success
 */
int main(int __attribute__ ((unused)) ac, char **av, char **env)
{
	char *command = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			print_string("$ ");
		}
		command = get_command();
		if (_strcmp("\n", command) == 0 || command == NULL)
		{
			free(command);
			exit(EXIT_SUCCESS);
		}
		if (_strcmp("exit\n", command) == 0 || command == NULL)
		{
			free(command);
			exit(EXIT_SUCCESS);
		}
		if (execute_shell(command, av, env) == -1)
		{
			break;
		}
	}
	free(command);

	return (0);
}
