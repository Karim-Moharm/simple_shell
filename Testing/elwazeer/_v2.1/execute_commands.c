#include "main.h"

/**
 * execute - execute command
 * @av: pointer to av
 * Return: 0 on success or -1 on Fail
 */
int execute(char **av)
{
	if (execve(av[0], av, NULL) == -1)
	{
		perror(av[0]);
		return (-1);
	}
	return (0);
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
			av[0] = command;
		else
			av[0] = cmd;
		if (execute(av) == -1)
		{
			free(av);
			free(command);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		free(av);
		free(command);
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
}
