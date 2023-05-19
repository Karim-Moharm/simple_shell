#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - Entry Point
 * Return: Always 0
 */
int main(int __attribute__((unused)) argc, char *argv[])
{
	int i;
	char *token;
	char *str_copy = NULL;

	for (int i = 0; argv[i] != NULL; i++)
	{
		str_copy = (char *)malloc(strlen(argv[i]) + 1);
		if (str_copy == NULL)
			return (1);
		strcpy(str_copy, argv[i]);
	}

	token = strtok(str_copy, " ,");
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ,");
	}
	free(str_copy);
	return (0);
}
