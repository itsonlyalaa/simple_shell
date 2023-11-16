#include "shell.h"

#define SETOWD(V) (V = _strdup(_getenv("OLDPWD")))
/**
 * c_d - changes directory
 * @data: pointer to data structure
 *
 * Return: if succes 0 will be returned
 * and if failed negative number will be returned
 */
int c_d(s_t *data)
{
char *home;

home = _getenv("HOME");
if (data->arg[1] == NULL)
{
SETOWD(data->o_pwd);
if (chdir(home) < 0)
return (FAILURE);
return (SUCCESS);
}
if (_strcmp(data->arg[1], "-") == 0)
{
if (data->o_pwd == 0)
{
SETOWD(data->o_pwd);
if (chdir(home) < 0)
return (FAILURE);
}
else
{
SETOWD(data->o_pwd);
if (chdir(data->o_pwd) < 0)
return (FAILURE);
}
}
else
{
SETOWD(data->o_pwd);
if (chdir(data->arg[1]) < 0)
return (FAILURE);
}
return (SUCCESS);
}
#undef GETCWD
/**
* _exiting - exit the program
* @data: pointer to data structure
*
* Return: if success 0 is returned
* and if failed negative number will be returned
*/
int _exiting(s_t *data __attribute__((unused)))
{
int code, i = 0;

if (data->arg[1] == NULL)
{
free_d(data);
exit(errno);
}
while (data->arg[1][i])
{
if (_isalpha(data->arg[1][i++]) < 0)
{
data->error = _strdup("Illegal number\n");
return (FAILURE);
}
}
code = _atoi(data->arg[1]);
free_d(data);
exit(code);
}
/**
* display_h - display the help menu
* @data: pointer to data structure
*
* Return: if success 0 is returned
* and if failed negative number will be returned
*/
int display_h(s_t *data)
{
int fd, fw, rd = 1;
char c;

fd = open(data->arg[1], O_RDONLY);
if (fd < 0)
{
data->error = _strdup("no help topics match\n");
return (FAILURE);
}
while (rd > 0)
{
rd = read(fd, &c, 1);
fw = write(STDOUT_FILENO, &c, rd);
if (fw < 0)
{
data->error = _strdup("cannot write: permission denied\n");
return (FAILURE);
}
}
PRINT("\n");
return (SUCCESS);
}
/**
* handle_b - handle and manage the builtins cmd
* @data: pointer to data structure
*
* Return: if success 0 is returned
* and if failed negative number will be returned
*/
int handle_b(s_t *data)
{
blt_t blt[] = {
{"exit", _exiting},
{"cd", c_d},
{"help", display_h},
{NULL, NULL}
};
int i = 0;

while ((blt + i)->cmd)
{
if (_strcmp(data->arg[0], (blt + i)->cmd) == 0)
return ((blt + i)->f(data));
i++;
}
return (FAILURE);
}
