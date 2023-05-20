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
    char *lineptr = NULL;  
    pid_t child_pid = 0;
    int status;

    while (1)
    {
        lineptr = _getline();

        /* if (lineptr == "ls" || lineptr == "ls -l")
        {
            excute_ls();
            
        }

        else
        {
        } */
        
        av = tokenize(lineptr);


        if (strcmp(av[0], "env") == 0)
        {
            print_env();
            free_2D(av);
            continue;
        }

        if (strcmp(av[0], "exit") == 0)
        {
            free(av);
            free(lineptr);
            exit(EXIT_SUCCESS);
        }
            /* break */;

        child_pid = fork();

        if (child_pid < 0)
        {
            perror("fork");
            return 1;
        }
        else if (child_pid == 0)
        {
            /* check if command is full bath or not */
            
                if (search_for_char(av[0], '/') == 0) /* not full bath command like ls or ls -l */
                {
                    /* SEARCH IN PATH FOR COMMAND */
                }

                if (execve(av[0], av, envp) == -1)
                {
                    perror(av[0]);
                    exit(EXIT_FAILURE);
                    break;
                }
        }
        else
        {
            wait(&status);
            free(av);
        }             
    }

    free(lineptr);

    return 0;
}



