#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char **tokenize(char *lineptr)
{
	char **command = NULL;
	char *token, *delim = " \n\t";
	int tok_counter = 0;

	command = (char **)malloc(sizeof(char *) * PATH_MAX_SIZE); 

	if (command == NULL)
	{
		free_2D(command);
		exit(EXIT_FAILURE);
	}

	token = strtok(lineptr, delim);
    if (token == NULL)
    {
        free_2D(command);
		exit(EXIT_FAILURE);
    }

	while (token)
	{
		command[tok_counter] = _strdup(token);
		token = strtok(NULL, delim);
		tok_counter++;
	}
	command[tok_counter] = NULL;
	return (command);
}