#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_SIZE 1024

extern char **environ;

int _putchar(char c);
int _puts(char *str);
int print_string(char *str);

char *_strcpy(char *dest, char *src);
int _strcmp(char *str1, char *str2);
int _strlen(char *str);
char *_strdup(char *str);
int _strncmp(char *str1, char *str2, unsigned int n);

char *get_command();

char **get_path();
char *search_in_path(char *str);
char *full_path(char *dir, char *cmd);

char **split_string(char *str, char *delim);

void execute(char **av);
void execute_shell(char *command);

char *_getenv(char *name);
void print_env(void);

void free_2D(char **arr);

void handle_exit(char **av, char *cmd);
int handle_env(char **av);

#endif
