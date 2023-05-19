#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;
    int n;
    int i = 0;
    int status;

    printf("before fork--excuted only one time\n");

    pid = fork();
    
    if (pid == -1)
    {
        perror("fork failed");
        return (-1);
    }
    else if (pid == 0)
    {
        /* in child process */
        n = 1;   // if in child process start count form 1 
    }
    else 
    {
        wait(&status);
        n = 5;   // if in parent start count form 5
    }

    for (i = n; i < n + 5; i++)
    {
        printf("%d ", i);
        fflush(stdout);
    }
    printf("\n");
    printf("after fork--excuted twice\n");

}

