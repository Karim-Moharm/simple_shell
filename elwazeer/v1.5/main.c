#include "main.h"

/**
 * main - Entry point
 * Return: 0 when success
 */
int main(void)
{
	char *command = NULL, *cmd = NULL;
	char **av = NULL;
	pid_t pid;
	int status;

	while (1)
	{
		free(command);
		print_string("($) ");
		command = get_command();
		if (_strcmp("exit\n", command) == 0)
		{
			free(command);
			exit(EXIT_SUCCESS);
		}

		pid = fork();
		if (pid == 0)
		{
			if (_strcmp("env\n", command) == 0)
				print_env();
			av = split_string(command, " \n");
			cmd = serach_in_path(av[0]);
			/* return to original command if not found and also return if value /bin/ls */
			if (cmd == NULL)
				av[0] = command;
			else
				av[0] = cmd;
			execute(av);
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
	}
	return (0);
}