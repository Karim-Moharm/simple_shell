#include "shell.h"

/**
 * search_for_char - unsed to search for / in command entered by user
 * @cmd: the command entered by user
 * @ch: char to search for
 * 
 * return: 1 if the char was found, 0 if not found
*/
int search_for_char(char *cmd, char ch)
{
    while (*cmd)
    {
        if (*cmd == ch)
            return (1);
        cmd++;
    }
        return (0);
}

char* search_in_Path(char *cmd)
{
    char *path = NULL;
    char *tok_path = NULL;
    char *path_dir[PATH_MAX_SIZE];
    /* char **path_dir; */
    int path_count = 0;
    struct stat st;
    char *old_wd;

    old_wd = getcwd(NULL, PATH_MAX_SIZE);
    
    path = getenv("PATH");
    tok_path = strtok(path, ":");

    /* path_dir = (char **) malloc(sizeof(char *) * 1024); */

    while (tok_path)
    {
        path_dir[path_count] = tok_path;
        /* path_dir[path_count] = strdup(tok_path); */
        tok_path = strtok(NULL, ":");
        path_count++;
    }
    path_dir[path_count] = NULL;
    
    path_count = 0;
    while (path_dir[path_count])
    {
        /* change the dir to the path dir to search in it */
        chdir(path_dir[path_count]);
        if (stat(cmd, &st) == 0)  
        {
            path_dir[path_count] = _strcat(path_dir[path_count], "/");
            cmd = _strcat(path_dir[path_count], cmd);
            break;
        }
        path_count++;
    }
    chdir(old_wd);
    free(old_wd);
    /* free_2D(path_dir); */

    return (cmd);
} 