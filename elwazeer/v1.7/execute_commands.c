#include "main.h"

/**
 * execute - execute command
 * @av: pointer to av
 * Return: 0 success and -1 on fail
 */
void execute(char **av)
{
	if (execve(av[0], av, NULL) == -1)
	{
		perror(av[0]);
		exit(EXIT_FAILURE);
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

	pid = fork();
	if (pid == 0)
	{
		if (_strcmp("env\n", command) == 0)
		{
			print_env();
			free(command);
			exit(EXIT_SUCCESS);
		}
		av = split_string(command, " \n");
		cmd = serach_in_path(av[0]);
/* return to original command if not found and also return if value /bin/ls */
		if (cmd == NULL)
			_strcpy(av[0], command);
		else
			_strcpy(av[0], cmd);
		execute(av);
	}
	else if (pid < 0)
	{
		free_2D(av);
		free(command);
		free(cmd);
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	else
		wait(&status);
}
