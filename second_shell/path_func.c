#include "shell.h"

/**
 * search_for_char - unsed to search for / in command entered by user
 * @cmd: the command entered by user
 * @ch: char to search for
 *
 * Return: 1 if the char was found, 0 if not found
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
 * search_in_Path - search in path for commadn
 * * @cmd: user inout command
 *
 * Description: search in path variable for user input command
 * and concatenate it to be a directory so it be excuted
 *
 * Return: full dir path of thr command
 */

char *search_in_Path(char *cmd, int *flag)
{
	char *path = NULL;
	char *tok_path = NULL;
	char *path_dir[PATH_MAX_SIZE];
	int path_count = 0;
	struct stat st;
	char *old_wd;

	*flag = 0;
	old_wd = getcwd(NULL, PATH_MAX_SIZE);
	path = getenv("PATH");
	tok_path = strtok(path, ":");

	while (tok_path)
	{
		path_dir[path_count] = tok_path;
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
			*flag = 1;
			break;
		}
		path_count++;
	}
	chdir(old_wd);
	free(old_wd);

	return (cmd);
}
