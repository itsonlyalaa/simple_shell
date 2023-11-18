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
