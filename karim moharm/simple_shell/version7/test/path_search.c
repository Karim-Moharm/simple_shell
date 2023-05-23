#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

/**
 * free_2D - deallocate an array of pointer to string
 * @arr: pointer to pointer string
 * Return: Nothing  
*/
void free_2D(char **arr)
{
    int i = 0;

    for (i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}


char* search_in_Path_2(char *cmd)
{
    char *path = NULL;
    char *tok_path = NULL;
    char **path_dir = NULL;
    int path_count = 0;
    struct stat st;

    path = getenv("PATH");
    printf("path before token\n\n %s \n", path);
    tok_path = strtok(path, ":");
    printf("path after token\n\n %s \n", path);

    path_dir = (char **) malloc(sizeof(char *) * 1024);

    while (tok_path)
    {
        printf("entered while_1\n");
        /* path_dir[path_count] = tok_path; */
        /* path_dir[path_count] = tok_path; */
        path_dir[path_count] = strdup(tok_path);
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
            free_2D(path_dir);
            break;
        }
        path_count++;
    }
    free_2D(path_dir);
    return (cmd);
} 


int main(void)
{
    char *cmd;

    cmd = search_in_Path_2("pwd");

    printf("cmd = %s\n", cmd);

    return 0;

}