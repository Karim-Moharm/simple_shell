#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[], char *envp[])
{
    pid_t pid;
    int i;
    char *pathname = "/bin/ls";
    char *av []= {"ls", "-l", "/tmp", NULL};
    int status; 

    for (i = 0; i < 5; i++)
    {
        pid = fork();

        if (pid < 0)
        {
            perror("Fork failed\n");
        }

        else if (pid == 0) {
            execve(pathname, av, envp);
        }

    }

    for (i = 0; i < 5; i++)
    {
        wait(&status);
    }
   
   return 0; 
}

