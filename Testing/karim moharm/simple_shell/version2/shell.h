#ifndef _SHELL_H
#define _SHELL_H


extern char **environ;

int _putchar (char c);
int _puts(char *str);
void free_2D(char **arr);
char *_getline(void);
void print_env();
char **tokenize(char *lineptr);
char *_getenv(const char *name);
char* _strdup(const char* str);
int search_for_char(char *cmd, char ch);
#endif
