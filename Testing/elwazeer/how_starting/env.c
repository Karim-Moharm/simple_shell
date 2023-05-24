#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
    /* unsigned int i;

    i = 0;
    while (env[i] != NULL)
    {
        printf("%s\n", env[i]);
        i++;
    }

    char *envv = getenv("PATH");
    printf("%s", envv); */

    int i = 0;

    // Using environ or env to access environment variables
    while (environ[i] != NULL)
    {
        printf("%s\n", environ[i]);
        i++;
    }

    return (0);
}