#include "shell.h"

volatile sig_atomic_t is_interrupted = 0;

/**
 */

void handle_signal (int signum)
{
	if (signum == SIGINT)
	{
		is_interrupted = 1;
	}
}

/**
 * main - main function of the shell
 * @argc: argument counter (unused)
 * @av: argument vector
 * @envp: environment variable
 *
 * Return:0 on success
 *
*/


int main(__attribute__((unused)) int argc, char **av, char *envp[])
{
	char *lineptr = NULL;
	size_t n = 0;

	signal(SIGINT, handle_signal);

	while (1)
	{

		/*lineptr = _getline();*/
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		if (getline(&lineptr, &n, stdin) == -1)
		{
			free(lineptr);
			exit(EXIT_SUCCESS);
		}
		if (lineptr == NULL)
		{
			exit(EXIT_SUCCESS);
		}

		av = tokenize(lineptr);
		if (av[0] == NULL)
			break;

		if (_strcmp(av[0], "env") == 0)
		{
			print_env();
			free(av);
	/*		free(lineptr);*/
			continue;
		}

		if (is_interrupted)
		{
			free(lineptr);
			_puts("\n");
			exit(EXIT_SUCCESS);

		}

		handle_exit(av, lineptr);
		excute_commands(av, envp, lineptr);
	}
	free_2D(av);
	free(lineptr);
	return (0);
}
