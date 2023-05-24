#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("pid is %d\n ppid is %d\n", getpid(), getppid());

    return 0;
}

