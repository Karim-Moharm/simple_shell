#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[], char **envp)
{
    /* int execve(const char *pathname, char *const argv[], char *const envp[]) */

    char *pathname = "/bin/ls";
    char *av[] = {"ls", "-l", NULL};

    if (execve(pathname, av, envp) == -1);
    {

    return 0;

}
