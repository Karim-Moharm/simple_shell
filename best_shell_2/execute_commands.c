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
 * @av: pointer to content
 * @env: pointer to pointer
 * Return: 0 succees or -1 fail
 */
int execute_shell(char *command, char **av, char **env)
{
	pid_t pid;
	int status;
	char *cmd = NULL;
	int i = 0;

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
		for (i = 0; av[i]; i++)
			printf("xx = %s\n", av[i]);
		if (av == NULL)
			return (-1);
		cmd = serach_in_path(av[0]);
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
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else
		wait(&status);
	return (0);
}
