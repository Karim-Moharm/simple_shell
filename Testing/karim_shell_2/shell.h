#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

extern char **environ;

#define PATH_MAX_SIZE 1024

int _putchar (char c);
int _puts(char *str);
int _strcmp(const char *str1, const char *str2);
char *_strdup(const char *str);
char *_strcat(char *dest, const char *src);
int _strlen(const char *s);
int _strncmp(char *s1, const char *s2, int n);

void free_2D(char **arr);
void handle_exit(char **argv, char *cmd);
void print_env(void);
char *_getenv(const char *name);
void excute_commands(char **argv, char **env, char *cmd);

char **tokenize(char *lineptr);
int search_for_char(char *cmd, char ch);
char *search_in_Path(char *cmd);

#endif
