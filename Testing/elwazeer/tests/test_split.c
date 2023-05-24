#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split_string(char *str);

int main()
{
    char str[50] = "mahmoud ali";
    char **tokens = split_string(str);

    for (int i = 0; i < 10; i++)
    {
        printf("Token %d: %s\n", i, tokens[i]);
    }

    // Free the allocated memory
    for (int i = 0; i < 20; i++)
    {
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}

char **split_string(char *str)
{
    int max_split = 20;
    char **splits;
    char *split;
    int count = 0;
    char *command;

    command = strdup(str);

    splits = (char **)malloc(sizeof(char *) * max_split);

    split = strtok(str, " ");
    while (split != NULL)
    {
        splits[count++] = strdup(split);
        split = strtok(NULL, " ");
    }
    splits[count] = NULL;

    free(command);
    return (splits);
}
