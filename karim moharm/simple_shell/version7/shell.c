#include "shell.h"
/**
 * main - main function of the shell
 * @argc: argument counter (unused)
 * @av: argument vector
 * @envp: environment variable
 *
 * Return:0 on success
 *
*/

int main(__attribute__((unused)) int argc, char *av[], char *envp[])
{
	char *lineptr = NULL;

	while (1)
	{
		lineptr = _getline();
		
	/*	if (isatty(STDIN_FILENO))
			_puts("$ ");

		if (getline(&lineptr, &n, stdin) == -1)
			break;
		if (lineptr == NULL)
			exit(0);*/

		av = tokenize(lineptr);
		if (av[0] == NULL)
		{
			free(av);
			continue;
		}

		if (_strcmp(av[0], "env") == 0)
		{
			print_env();
			free(lineptr);
			continue;
		}

		handle_exit(av, lineptr);
		excute_commands(av, envp, lineptr);
		free(lineptr);
	}
/*	free(lineptr);*/
	return (0);
}
