#include "main.h"

/**
 * get_path - get paths
 * Return: directory of pathes
 */
char **get_path()
{
	char **av;
	char *envv;

	envv = _getenv("PATH");
	av = split_string(envv, ":");
	return (av);
}

/**
 * serach_in_path - search in path
 * @str: pointer to command
 * Return: path of command
 */
char *serach_in_path(char *str)
{
	char **av;
	int count = 0;
	char *old_wd;
	struct stat st;

	old_wd = getcwd(NULL, MAX_SIZE);
	av = get_path();
	while (av[count])
	{
		chdir(av[count]);
		if (stat(str, &st) == 0)
		{
			_strcat(av[count], "/");
			str = _strcat(av[count], str);
			printf("s = %s", str);
			break;
		}
		count++;
	}
	chdir(old_wd);
	free(old_wd);
	return (str);
}

/**
 * check_path - the status
 * @str: pointer to path
 *  Return: 1 found or 0 not found
 */
int check_path(char *str)
{
	struct stat st;

	if (stat(str, &st) == 0)
		return (1);

	return (0);
}

/**
 * print_env - print environment
 * Return: void
 */
void print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

/**
 * _getenv - get environment
 * @name: pointer to string of variable
 * Return: value of variable
 */
char *_getenv(char *name)
{
	int i = 0, len = _strlen(name);
	char **env = environ;

	while (env[i] != NULL)
	{
		if ((_strncmp(env[i], name, len) == 0) && env[i][len] == '=')
			return (&env[i][len + 1]);
	i++;
	}
	return (NULL);
}
