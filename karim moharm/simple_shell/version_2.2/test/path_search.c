#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

/* int search_in_Path(char *cmd)
{
    char *path = getenv("PATH");
    char *token = NULL;
    int check_access = 0;
    int found = 0;

    token = strtok(path, ":");
    while(token)
    {
        if ((check_access = access(cmd, X_OK)) == 0)
        {
            printf("command==> %s is found ", cmd);
            found = 1;
            break;
        }
        token = strtok(NULL, ":");
    }

    return (found);

} */

char* search_in_Path_2(char *cmd)
{
    char *path = NULL;
    char *tok_path = NULL;
    char *path_dir = NULL;
    int path_count = 0;
    struct stat st;

    path = getenv("PATH");
    printf("path before token\n\n %s \n", path);
    tok_path = strtok(path, ":");
    printf("path after token\n\n %s \n", path);

    while (tok_path)
    {
        printf("entered while_1\n");
        /* path_dir[path_count] = tok_path; */
        path_dir[path_count] = tok_path;
        tok_path = strtok(NULL, ":");
        path_count++;
    }
    path_dir[path_count] = '\0';
    
    path_count = 0;
    while (path_dir[path_count])
    {
        /* change the dir to the path dir to search in it */
        chdir(path_dir[path_count]);
        if (stat(cmd, &st) == 0)  
        {
            printf(" the command ==> %s FOUND\n", cmd);
            strcat(path_dir[path_count], "/");
            strcat(cmd, path);
            break;
        }
        path_count++;
    }
    return (cmd);
} 

int main(void)
{
    char *cmd;

    cmd = search_in_Path_2("ls");

    printf("cmd = %s\n", cmd);

    return 0;

}