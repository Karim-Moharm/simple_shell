#include "shell.h"

/**
 * print_env - function that print the environment var
*/
void print_env(void)
{
	int i = 0;
	extern char **environ;

	while (environ[i])
	{
		_puts(environ[i++]);
		_puts("\n");
	}
}

/**
 * handle_exit - handle the exit state to exit the shell
 * @argv: argment vector
 * @cmd: command
 *
 * Return: void
*/

void handle_exit(char **argv, char *cmd)
{
	if (_strcmp(argv[0], "exit") == 0)
	{
		free(argv);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
}

/**
 * excute_commands - function that excute command
 * @argv: argument vector
 * @env: environment variables
 * @cmd: command to be excuted
 *
 * Return: void
 *
*/

void excute_commands(char **argv, char **env, char *cmd)
{
	pid_t child_pid = 0;
	int status;

	child_pid = fork();
	if (child_pid < 0)
	{
		free(argv);
		free(cmd);
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (search_for_char(argv[0], '/') == 0)
			argv[0] = search_in_Path(argv[0]);

		if (execve(argv[0], argv, env) == -1)
		{
			perror(argv[0]);
			free(cmd);
			free(argv);
			exit(EXIT_FAILURE);
		}
	}
	wait(&status);
	free(argv);
}
