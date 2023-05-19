#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"

extern char **environ;

int main(__attribute__((unused)) int argc, char *av[], char *envp[])
{
    size_t n = 0;
    char *lineptr = NULL;  /* if not allocated getline will allocate it */
                           /* but the user has to free is */
    pid_t child_pid = 0;
    int status;
    char *delim = " \n\t";

    while (1)
    {
        lineptr = _getline();
        /* tokenize lineptr */
     
/*         av = strtok(lineptr, delim);   /* error */

        av = tokenize(lineptr);



       if (strcmp(av[0], "env") == 0)
       {
            print_env();
            free_2D(av);
            continue;
       }

       if (strcmp(av[0], "exit") == 0)
       {
            exit(EXIT_SUCCESS);
            free_2D(av);
            free(lineptr);
       }

        child_pid = fork();

        if (child_pid < 0)
        {
            perror("fork");
            return 1;
        }
        else if (child_pid == 0)
        {

            char *av[] = {lineptr, NULL};

        if (execve(av[0], av, envp) == -1)
            perror(av[0]);
        }
        else
        {
        wait(&status);
        }   
    }

    free(lineptr);

    return 0;
}


char *_getline(void)
{
    char *lineRead = NULL;
    size_t lineSize = 0;

    if (isatty(STDERR_FILENO)) /* check if the file referes to terminal or not (interactive mode)*/
    {
        _puts("$ ");
    }

    if (getline(&lineRead, &lineSize, stdin) == -1)
    {
        free(lineRead);
        exit(EXIT_SUCCESS);
    }

    return (lineRead);
}


void print_env()
{
    char **env = environ;

     while (*env)
    {
        _puts(*env++);
        _puts("\n");
    }
}


