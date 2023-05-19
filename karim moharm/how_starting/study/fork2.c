#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    int value = 5;
    pid_t pid;

    pid = fork(); // child process is created

    /**
     * if pid = 0 -> child process
     * if pid > 0 -> parent process
     * if pid < 0 -> Error and -1 is returned
     *
     */

    /**
     * the code is divided into 3 areas
     * 1. child area -> excuted first if pid = 0
     * 2. parent area -> excuted after child process
     * 3. common area -> excuted twice, once with child and the other with parent (the area after else in this code)
     *
     */

    /**
     * working of code in case of fork()
     * 1. if pid = 0, child working and excute the code in its area
     * 2. then excute the code in common area if there is no exit in the child area
     * 3. parent process is woring and excute the code in its area
     * 4. the common area got excuted again but this time because of parent
     *
     */

    if (pid < 0)
    {
        perror("error using fork");
        return (-1);
    }
    else if (pid == 0)
    {
        /* we are now in child process area*/
        printf("In Child_1 Process\n");
        value += 10;
        printf("value in child_1 is %d and pid is %d\n", value, getpid());
        exit(0); // will exit from child process and go to parent process not the common area
    }
    else
    {
        wait(NULL);
        /* we are now in parent process area*/
        printf("In parent Process\n");
        pid = fork(); // another fork // creating another child process
        if (pid == 0)
        {
            value += 20;
            printf("value in child_2 is %d and pid is %d\n", value, getpid());
        }
        /* else // now we in parent process
             printf("In Parent\n"); */
    }

    /* common area, this area excute twice
     * with parent and child
     */

    value = value + 1;
    printf("value is %d and the pid is %d\n", value, getpid());
}
