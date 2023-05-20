#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Entry point
 * Return: 0 when success
 */
int main(void)
{
	/* char *command == NULL;
	pid_t pid;
	int status;

	while (1)
	{
		print_string("($) ");
		pid = fork();

		if (pid == 0)
		{
			command = get_command();
			check_command(command);
		}
		else if (pid < 0)
			exit(0);
		else
			wait(&status);
	} */

	char *envv = _getenv("PATH");
	printf("%s", envv);
	return (0);
}
