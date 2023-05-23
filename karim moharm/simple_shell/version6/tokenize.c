#include "shell.h"

/**
 * tokenize - unsed to split input into tokens
 * @lineptr: input command
 *
 * Return: tokenized command
*/

char **tokenize(char *lineptr)
{
	char **command = NULL;
	char *token, *delim = " \n\t";
	int tok_counter = 0;
/*	char *free_cmd;*/
	
/*	free_cmd = _strdup(lineptr);*/
	command = (char **)malloc(sizeof(char *) * PATH_MAX_SIZE);
	
	if (command == NULL)
	{
		free(command);
		perror("allocate");
		exit(EXIT_FAILURE);
	}

	token = strtok(lineptr, delim);

	while (token)
	{
	/*	command[tok_counter] = _strdup(token);*/
		command[tok_counter] = token;
		token = strtok(NULL, delim);
		tok_counter++;
	}
	command[tok_counter] = NULL;
/*	free(free_cmd);*/

	return (command);
}
