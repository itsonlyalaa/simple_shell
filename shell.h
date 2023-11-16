#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;

#define BUFFSIZE 1024
#define TOKSIZE 256
#define PRINT(c) (write(STDOUT_FILENO, c, _strlen(c)))
#define PT "$ "
#define SUCCESS (1)
#define FAILURE (-1)
#define NEUTRAL (0)

/**
 * struct s_data - global structure data, has all the variables needed
 * @line: line input
 * @arg: argument token
 * @error: global path
 * @cmd: parsed command
 * @index: command index
 * @o_pwd: old path
 * @env: environment
 */
typedef struct s_data
{
        char *line;
        char **arg;
        char *cmd;
        char *error;
        char *o_pwd;
        unsigned long int index;
        char *env;
} s_t;

/**
 * struct built_in - manage  builtin functions
 * @cmd: commnand on string form
 * @f: associated function
 */
typedef struct built_in
{
        char *cmd;
        int (*f)(s_t *data);
} blt_t;

int _readline(s_t *);
int _splitline(s_t *);
int _parseline(s_t *);
int _cmd(s_t *);

char *_strdup(char *str);
char *_strcat(char *ft, char *sd);
int _strlen(char *str);
char *_strchr(char *str, char c);
char _strcmp(char *s1, char *s2);

char *_strcpy(char *d, char *s);

void *_realloc(void *p, unsigned int o_size, unsigned int n_size);
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *d, char *s, unsigned int n);
int free_d(s_t *);

void *fill(void *a, int l, unsigned int lens);
void signal_h(int sign);
char *_getenv(char *path_n);
void i_cmd(s_t *data);
void rev(char *ar, int lens);

char *_itoa(unsigned int n);
int intlens(int nums);
int _atoi(char *c);
int p_error(s_t *data);
int w_history(s_t *data);
int _isalpha(int c);

int _exiting(s_t *data);
int c_d(s_t *data);
int display_h(s_t *data);
int handle_b(s_t *data);
int check_b(s_t *data);

int path_f(s_t *data);
void short_f(s_t *data);
int is_bltin(s_t *data);

#endif
