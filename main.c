#include "main.h"

/**
 * main - Entry point
 * @ac: number
 * @av: pointer to content
 * @env: pointer to pointer
 * Return: 0 when success
 */
int main(int __attribute__ ((unused)) ac, char *av[], char **env)
{
	char *command = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			print_string("$ ");
		}
		command = get_command();
		av = split_string(command, " \n\t");
		if (av[0] == NULL || _strcmp(av[0], "exit") == 0)
		{
			break;
		}
		execute_shell(command, av, env);
		free(command);
		free_2D(av);
	}
	free_2D(av);
	free(command);
	exit(EXIT_SUCCESS);

	return (0);
}
