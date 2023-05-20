#include "shell.h"


/**
 * main - main function of the shell
 * @argc: argument counter (unused)
 * @av: argument vector
 * @envp: environment variable
 * 
 * Return:0 on success
 * 
*/

int main(__attribute__((unused)) int argc, char *av[], char *envp[])
{
    char *lineptr = NULL;  
    pid_t child_pid = 0;
    int status; /* found = 0; */

    while (1)
    {
        lineptr = _getline();
        av = tokenize(lineptr);


        if (_strcmp(av[0], "env") == 0)
        {
            print_env();
            free_2D(av);
            continue;
        }

        if (_strcmp(av[0], "exit") == 0)
        {
            free_2D(av);
            free(lineptr);
            exit(EXIT_SUCCESS);
        }

        child_pid = fork();
        if (child_pid < 0)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (child_pid == 0)
        {
            /* check if command is full bath or not */
            /* not full bath command like ls or ls -l */
                if (search_for_char(av[0], '/') == 0) 
                    av[0] = search_in_Path (av[0]);
                
                if (execve(av[0], av, envp) == -1)
                {
                    perror(av[0]);
                    exit(EXIT_FAILURE);
                    free_2D(av);
                    free(lineptr);
                }
        }
        else
        {
            wait(&status);
            free_2D(av);
            free(lineptr);
        }             
    }

    free(lineptr);

    return 0;
}