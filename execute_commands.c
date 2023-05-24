#include "main.h"

/**
 * execute - execute command
 * @av: pointer to av
 * Return: void
 */
void execute(char **av)
{
	if (execve(av[0], av, NULL) == -1)
	{
		perror(av[0]);
		free_2D(av);
	}
}

/**
 * execute_shell - execute shell
 * @command: pointer to command
 * Return: void
 */
void execute_shell(char *command)
{
	pid_t pid;
	int status;
	char *cmd = NULL;
	char **av = NULL;


	av = split_string(command, " \n");
	handle_exit(av, command);
	if (handle_env(av) == 0)
		return;
	cmd = search_in_path(av[0]);
	if (cmd == NULL)
	{
		free(cmd);
		execute(av);
		return;
	}
	else
	{
		free(av[0]);
		av[0] = (char *)malloc(sizeof(char) * MAX_SIZE);
		_strcpy(av[0], cmd);
	}
	free(cmd);

	pid = fork();
	if (pid == 0)
	{
		execute(av);
	}
	else if (pid < 0)
	{
		free_2D(av);
		free(command);
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	else
		wait(&status);
}

/**
 * handle_exit - handle the exit status
 * @av: pointer to array
 * @cmd: pointer to command
 * Return: void
 */
void handle_exit(char **av, char *cmd)
{
	if (_strcmp(av[0], "exit") == 0)
	{
		free(av);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
}

/**
 * heandle_env - handle the env
 * @av: pointer to array
 * @cmd: pointer to command
 * Return: 0 on SUCCESS -1 fail
 */
int handle_env(char **av)
{
	if (_strcmp(av[0], "env") == 0)
	{
		print_env();
		free_2D(av);
		return (0);
	}
	return (-1);
}
