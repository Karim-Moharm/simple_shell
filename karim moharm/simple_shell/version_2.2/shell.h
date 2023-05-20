#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

extern char **environ;

int _putchar (char c);
int _puts(char *str);
void free_2D(char **arr);
char *_getline(void);
void print_env();
int _strcmp(const char *str1, const char *str2);
char **tokenize(char *lineptr);
char *_getenv(const char *name);
char* _strdup(const char* str);
int search_for_char(char *cmd, char ch);
int search_in_Path(char *cmd);
#endif
