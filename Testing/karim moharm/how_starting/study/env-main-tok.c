#include <stdio.h>

/**
 * main - prints the environment
 * 
 * Return: Always 0.
 */

int main(int ac, char **av, char **envp)
{
    
   // char **env_var = envp;

    while (*envp)
    {
        printf("%s\n", *envp++);
    }
    
    return 0;
}
