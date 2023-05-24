#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void free_2D(char **arr);
char **tokenize(char *lineptr);

int main()
{
    char *str;
    str = "Mahmoud Mohamed";

    char **tokens = tokenize(str);

    for (int i = 0; i < 10; i++)
    {
        printf("Token %d: %s\n", i, tokens[i]);
    }

    // Free the allocated memory
    free_2D(tokens);

    return 0;
}

char **tokenize(char *lineptr)
{
    char **command = NULL;
    char *token, *delim = " \n\t";
    int tok_counter = 0;

    command = (char **)malloc(sizeof(char *) * 1024);

    if (command == NULL)
    {
        free(command);
        exit(EXIT_FAILURE);
    }

    token = strtok(lineptr, delim);
    if (token == NULL)
    {
        free(command);
        exit(EXIT_FAILURE);
    }

    while (token)
    {

        command[tok_counter] = strdup(token);
        token = strtok(NULL, delim);
        tok_counter++;
    }
    command[tok_counter] = NULL;
    return (command);
}

void free_2D(char **arr)
{
    int i = 0;

    for (i = 0; i < 1024; i++)
        free(arr[i]);
    free(arr);
}