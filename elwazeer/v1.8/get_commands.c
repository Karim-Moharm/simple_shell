#include "main.h"

/**
 * get_command - create new command
 * Return: command
 */
char *get_command()
{
	char *str = NULL;
	size_t size = 0;
	ssize_t check_read;

	check_read = getline(&str, &size, stdin);
	if (check_read == -1)
		return (NULL);

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
	char *split = NULL;
	int count = 0;

	splits = (char **)malloc(sizeof(char *) * MAX_SIZE);
	if (splits == NULL)
		return (NULL);

	split = strtok(str, delim);
	while (split)
	{
		splits[count] = split;
		split = strtok(NULL, delim);
		count++;
	}
	splits[count] = NULL;
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
