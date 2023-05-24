#include "shell.h"

void sigintHandler(int sig_num)
{
	(void) sig_num;
	fflush(stdout);
	_puts("\n");
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
	char av_name[1024];

	strcpy(av_name, av[0]);
	signal(SIGINT, sigintHandler);
	while (1)
	{
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
		{
			free(av);
			continue;
		}

		if (_strcmp(av[0], "env") == 0)
		{
			print_env();
			free(av);
			continue;
		}

		handle_exit(av, lineptr);
		excute_commands(av, envp, lineptr, av_name);
	}
	free(lineptr);
	return (0);
}
