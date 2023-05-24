#include "main.h"

/**
 * execute - execute command
 * @av: pointer to av
 * Return: 0 success and -1 on fail
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
void execute_shell(char **av, char *command)
{
	pid_t pid;
	int status;
	char *cmd = NULL;
	int i;

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
		for (i = 0; av[i]; i++)
			printf("%s\n", av[i]);
		cmd = serach_in_path(av[0]);
/* return to original command if not found and also return if value /bin/ls */
		if (cmd == NULL)
			_strcpy(av[0], command);
		else
			_strcpy(av[0], cmd);
		free(cmd);
		if (execute(av) == -1)
		{
			free(command);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		free(command);
		free(cmd);
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
}
