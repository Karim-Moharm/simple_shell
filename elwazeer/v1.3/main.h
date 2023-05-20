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
void check_command(char *str);
char *_getenv(char *name);

void execute_ls(char **av);
char **split_string(char *str, char *delim);
char **get_path();
char *serach_in_path(char *str);
void free_2D(char **arr);

void execute(char **av);
void print_env(void);

#endif
