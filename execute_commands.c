#include "main.h"

/**
 * execute - execute command
 * @av: pointer to av
 * @env: pointer to pointer
 * Return: 0 on success or -1 on Fail
 */
int execute(char **av, char **env)
{
	if (execve(av[0], av, env) == -1)
	{
		perror(av[0]);
		return (-1);
	}
	return (0);
}

/**
 * execute_shell - execute shell
 * @command: pointer to command
 * @env: pointer to pointer
 * Return: void
 */
void execute_shell(char *command, char **env)
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
		av = split_string(command, " \t\n");
		cmd = serach_in_path(av[0]);
/* return to original command if not found and also return if value /bin/ls */
		if (cmd != NULL)
		{
			free(av[0]);
			av[0] = (char *)malloc(sizeof(char) * MAX_SIZE);
			_strcpy(av[0], cmd);
		}
		free(cmd);
		if (execute(av, env) == -1)
		{
			free(command);
			free_2D(av);
			exit(EXIT_FAILURE);
		}
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
