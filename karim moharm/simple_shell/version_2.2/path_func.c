#include "shell.h"


/* int main(void)
{
    char *path = _getenv("PATH");
    char *token = NULL;
    
    token = strtok(path, ":");
    while(token)
    {
        _puts(token);
        _puts("\n");
        token = strtok(NULL, ":");
    }

    return 0;
}
 */

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

/**
 * search_in_Path - split the path into dirs and search for the command in it
 * @cmd: entered command 
 * Return: 1 if command found, 0 if not found
*/

/* int search_in_Path(char *cmd)
{
    char *path = _getenv("PATH");
    char *token = NULL;
    int found = 0;

    token = strtok(path, ":");
    while(token)
    {
        if (access(cmd, X_OK)) == 0)
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
    char *path_dir;
    int path_count = 0;
    struct stat st;

    path = getenv("PATH");
    tok_path = strtok(path, ":");

    while (tok_path)
    {
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
            strcat(*path_dir, "/");
            strcat(cmd, path);
            break;
        }
        path_count++;
    }
    return (cmd);
}