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
	size_t n = 0;

	while (1)
	{

		/*lineptr = _getline();*/
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		if (getline(&lineptr, &n, stdin) == -1)
		{
			free(lineptr);
			break;
		}
/*		if (lineptr == NULL)
		{
			free(lineptr);
			exit(EXIT_SUCCESS);
		}*/

		av = tokenize(lineptr);
		if (av[0] == NULL || _strcmp(av[0], "\n") == 0)
		{
			free(av);
			break;
		}

		if (_strcmp(av[0], "env") == 0)
		{
			print_env();
			free(lineptr);
			continue;
		}

		handle_exit(av, lineptr);
		excute_commands(av, envp, lineptr);
	}
	free(lineptr);
	return (0);
}
