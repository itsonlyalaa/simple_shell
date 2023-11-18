#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

int sh_ctrld(char **args);
int sh_cd(char **args);
int sh_help(char **args);
extern char **environ;
int sh_exit(char **args);
int _strcmp(char *s1, char *s2);
size_t _strncmp(char *s1, char *s2, size_t n);
int _strlen(char *s);
char *_strcpy(char *dst, char *src);
char *_strcat(char *dst, char *src);
int _putchar(char c);

char *get_path(char **env);
int _values_path(char **arg, char **env);
char *_getline_cmd(void);
void _getenv(char **env);
char **tokenizer(char *lineptr);
void _exit_cmd(char **args, char *lineptr, int _exit);
int _fork_func(char **arg, char **av, char **env,
char *lineptr, int np, int c);


#endif
