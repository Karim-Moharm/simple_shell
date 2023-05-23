#include "main.h"

/**
 * get_command - create new command
 * Return: command
 */
char *get_command()
{
	char *str = NULL;
	size_t size = 0;
/*	ssize_t check_read;*/

	if (getline(&str, &size, stdin) == -1)
	{
		free(str);
		return (NULL);
	}

	return (str);
}

/**
 * split_string - split strings
 * @str: pointer to string that will be splited
 * @delim: pointer to string that compare to split
 * Return: array of sring content new split strings
 */
char **split_string(char *str, char *delim)
{
	char **splits = NULL;
	char *split, *command;
	int count = 0;

	command = _strdup(str);

	splits = malloc(sizeof(char *) * MAX_SIZE);
	if (splits == NULL)
	{
/*		free(command);*/
		/*return (NULL);*/
		exit(EXIT_FAILURE);
	}

	split = strtok(str, delim);
	while (split != NULL)
	{
		splits[count] = _strdup(split);
		if (splits[count] == NULL)
		{
			free_2D(splits);
			free(command);
			return (NULL);
		}
		split = strtok(NULL, delim);
		count++;
	}
	splits[count] = NULL;
	free(command);
	return (splits);
}

/**
 * free_2D - free arr 2d
 * @arr: pointer to pointer
 * Return: void
 */
void free_2D(char **arr)
{
	int i = 0;

	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}
