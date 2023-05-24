#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1)
    {
        // Handle error condition
    }
    else if (pid == 0)
    {
        // Code for child process
        printf("Hello from child process!\n");
        exit(98);
    }
    else
    {
        // Code for parent process
        printf("Hello from parent process! Child process ID is %d\n", pid);
        printf("before wait\n");  // mostly printed before child
        wait(&status);
        printf("after wait\n");  // printed after child is terminated
      
        if (WIFEXITED(status))   // cheak if child exited normally 
        {
            // if child exited normally ise WEXITSTATUS to return code when child exits 
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        }
    }

    printf("End of program\n");

    return 0;
}
