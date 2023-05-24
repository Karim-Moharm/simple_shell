#include "main.h"

/**
 * main - Entry point
 * @ac: number
 * @av: pointer to content
 * Return: 0 when success
 */
int main(int __attribute__ ((unused)) ac, char *av[])
{
	char *command = NULL;

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
