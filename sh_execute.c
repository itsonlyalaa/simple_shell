#include "shell.h"

int sh_cd(char **args);
int sh_help(char **args);
int sh_exit(char **args);
int sh_ctrld(char **args);

/*
* List of builtin commands, followed by their corresponding functions.
*/
char *builtin_str[] = {"cd", "help", "exit", "^D"};

int (*builtin_func[]) (char **) = {&sh_cd, &sh_help, &sh_exit, &sh_ctrld};

/**
 * sh_num_builtins - size
 *
 * Return: size
 */

int sh_num_builtins(void)
{
return (sizeof(builtin_str) / sizeof(char *));
}

/**
 * sh_cd - builtin to change directory
 * @args: List of args.
 *
 * Return: 1 on success
 */

int sh_cd(char **args)
{
if (args[1] == NULL)
{
fprintf(stderr, "hsh: expected argument to \"cd\"\n");
}
else
{
if (chdir(args[1]) != 0)
{
perror("hsh");
}
}
return (1);
}

/**
 * sh_help - prints the help for the shell
 * @args: List of args.
 *
 * Return: Always returns 1, to continue executing.
 */

int sh_help(char **args)
{
int i;

printf("Oscar Bedat and Andres Henderson\n");
printf("If you need help, call 1-800-help\n");
(void)args;
for (i = 0; i < sh_num_builtins(); i++)
{
printf("  %s\n", builtin_str[i]);
}

return (1);
}

/**
 * sh_exit - builtin to exit the shell
 * @args: List of args.
 *
 * Return: Always returns 0, to terminate execution.
 */
int sh_exit(char **args)
{
(void)args;
free(args);
return (200);
}

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
*Return: 0 success
*
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
