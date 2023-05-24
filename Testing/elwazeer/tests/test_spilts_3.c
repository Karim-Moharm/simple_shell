#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int main()
{

    int max_split = 20;
    char *splits[20];
    char *split;
    int count = 0;

    // splits = (char **)malloc(sizeof(char *) * max_split);

    split = strtok("mahmoud mohamed ali", " ");
    while (split != NULL)
    {
        strcpy(splits[count], split);
        printf("%s\n", split);
        split = strtok(NULL, " ");
        count++;
    }
    splits[count] = NULL;

    return 0;
}
*/

int main()
{
    char str[80] = "This is www.tutorialspoint.com website";
    char *token;
    char *av[20];
    int count = 0;

    /* get the first token */
    token = strtok(str, " ");

    /* walk through other tokens */
    while (token != NULL)
    {
        printf(" %s\n", token);
        av[count] = strdup(token);
        token = strtok(NULL, " ");
        count++;
    }
    printf("============\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%s\n", av[i]);
    }

    return (0);
}
