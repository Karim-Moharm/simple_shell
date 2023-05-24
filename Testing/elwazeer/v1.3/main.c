#include "main.h"

/**
 * main - Entry point
 * Return: 0 when success
 */
int main(void)
{
	char *command = NULL;
	char **av;
	pid_t pid;
	int status;

	while (1)
	{
		print_string("($) ");
		command = get_command();
		if (_strcmp("exit\n", command) == 0)
			exit(0);
		pid = fork();

		if (pid == 0)
		{
			if (_strcmp("env\n", command) == 0)
				print_env();
			av = split_string(command, " \n");
			av[0] = serach_in_path(av[0]);
			execute(av);
		}
		else if (pid < 0)
			exit(0);
		else
			wait(&status);
	}

	return (0);
}
