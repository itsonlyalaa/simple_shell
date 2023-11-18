#include "shell.h"

int sh_ctrld(char **args);

/*
 * List of builtin commands, followed by their corresponding functions.
 */
char *builtin_str[] = {"cd", "help", "exit", "^D"};

int (*builtin_func[]) (char **) = {&sh_cd, &sh_help, &sh_exit, &sh_ctrld};
int sh_num_builtins(void);

/**
 * sh_ctrld - builtin to handle "^D" call
 * @args: List of args.
 *
 * Return: Always returns 0, to terminate execution.
 */
int sh_ctrld(char **args)
{
(void)args;
free(args);
return (200);
}

/**
 *_fork_func - foo that create a fork.
*@arg: Command and values path.
*@av: Has the name of our program.
*@env: Environment
*@lineptr: Command line for the user.
*@np: ID of proces.
*@c: Checker add new test
*
*Return: 0 success
*/

int _fork_func(char **arg, char **av, char **env, char *lineptr, int np, int c)
{

pid_t child;
int status, i = 0;
char *format = "%s: %d: %s: not found\n";

if (arg[0] == NULL)
return (1);
for (i = 0; i < sh_num_builtins(); i++)
{
if (_strcmp(arg[0], builtin_str[i]) == 0)
return (builtin_func[i](arg));
}
child = fork();
if (child == 0)
{
if (execve(arg[0], arg, env) == -1)
{
fprintf(stderr, format, av[0], np, arg[0]);
if (!c)
free(arg[0]);
free(arg);
free(lineptr);
exit(errno);
}
}
else
{
wait(&status);
return (status);
}
return (0);
}
