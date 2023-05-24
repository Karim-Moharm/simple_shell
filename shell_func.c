#include "shell.h"

/**
 * print_env - function that print the environment var
*/
void print_env(void)
{
	int i = 0;
	char **env = environ;

	while (env[i])
	{
		_puts(env[i++]);
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
 * @file_name: name of file
 *
 * Return: void
 *
*/

void excute_commands(char **argv, char **env, char *cmd, char file_name[1024])
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

			_puts("sh: 1: ");
			_puts(file_name);
			_puts(": not found\n");
			free(cmd);
			free(argv);
			exit(EXIT_FAILURE);
		}
	}
	wait(&status);
	free(argv);
}
