#include "shell.h"

/**
 * _getline - get the command from user 
 * 
 * Description: first check if the file referes to terminal or not (interactive mode)
 * using isatty function then prints $ and take the command from the user
 * 
 * Return: the entered command
*/
char *_getline(void)
{
    char *lineRead = NULL;
    size_t lineSize = 0;

    if (isatty(STDERR_FILENO)) /* */
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

/**
 * print_env - function that print the environment var
 * Return: nothing
*/
void print_env()
{
    char **env = environ;

    while (*env)
    {
        _puts(*env++);
        _puts("\n");
    }
}

/**
 * handle_exit - handle the exit state to exit the shell
 * argv - argment vector 
 * cmd: command 
 * 
 * Return: void
*/
void handle_exit(char **argv, char *cmd)
{
    if (_strcmp(argv[0], "exit") == 0)
        {
            free_2D(argv);
            free(cmd);
            exit(EXIT_SUCCESS);
        }
}

/**
 * 
*/
void excute_commands(char **argv, char **env, char *cmd)
{
    pid_t child_pid = 0;
    int status;

    child_pid = fork();
    if (child_pid < 0)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (child_pid == 0)
        {
                if (search_for_char(argv[0], '/') == 0) 
                    argv[0] = search_in_Path (argv[0]);
                
                if (execve(argv[0], argv, env) == -1)
                {
                    perror(argv[0]);
                    exit(EXIT_FAILURE);
                    /* free_2D(argv); */
                    free(cmd);
                }
        }
        else
        {
            wait(&status);
            /* free_2D(argv); */
        }             
}