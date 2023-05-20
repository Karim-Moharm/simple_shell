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
	char command[500];
	pid_t pid;
	int status;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			print_string("($) ");
		pid = fork();

		if (pid < 0)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
			/* break; */
		}

		if (pid == 0)
		{
			get_command(command);
			check_command(command);
		}
		
		else
			wait(&status);
	}
	return (0);
}