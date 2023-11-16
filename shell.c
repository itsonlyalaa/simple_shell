#include "shell.h"

/**
 * main - main function of the program
 *
 * Return: if success always 0
 */

int main(void)
{
s_t data;
int pl;

_memset((void *)&data, 0, sizeof(data));
signal(SIGINT, signal_h);
while (1)
{
i_cmd(&data);
if (_readline(&data) < 0)
{
if (isatty(STDIN_FILENO))
PRINT("\n");
break;
}
if (_splitline(&data) < 0)
{
free_d(&data);
continue;
}
pl = _parseline(&data);
if (pl == 0)
{
free_d(&data);
continue;
}
if (pl < 0)
{
p_error(&data);
continue;
}
if (_cmd(&data) < 0)
{
p_error(&data);
break;
}
free_d(&data);
}
free_d(&data);
exit(EXIT_SUCCESS);
}
/**
* _readline - reads line
* @data: pointer to struct of data
*
* Return: if success a positive number, if failed a negative number
*/

int _readline(s_t *data)
{
char *c_ptr, *e_ptr, c;
size_t size = BUFFSIZE, read_str, length, n_size;

data->line = malloc(size * sizeof(char));
if (data->line == NULL)
return (FAILURE);
if (isatty(STDIN_FILENO))
PRINT(PT);
for (c_ptr = data->line, e_ptr = data->line + size;;)
{
read_str = read(STDIN_FILENO, &c, 1);
if (read_str == 0)
return (FAILURE);
*c_ptr++ = c;
if (c == '\n')
{
*c_ptr = '\0';
return (SUCCESS);
}
if (c_ptr + 2 >= e_ptr)
{
n_size = size * 2;
length = c_ptr - data->line;
data->line = _realloc(data->line, size * sizeof(char),
n_size * sizeof(char));
if (data->line == NULL)
return (FAILURE);
size = n_size;
e_ptr = data->line + size;
c_ptr = data->line + length;
}
}
}

#define DELIMITER " \n\t\r\a\v"
/**
* _splitline - splits line to tokens
* @data: pointer to struct of data
*
* Return: if success a positive number, if failed a negative number
*/
int _splitline(s_t *data)
{
char *token;
size_t size = TOKSIZE, n_size, i = 0;

if (_strcmp(data->line, "\n") == 0)
return (FAILURE);
data->arg = malloc(size * sizeof(char *));
if (data->arg == NULL)
return (FAILURE);
token = strtok(data->line, DELIMITER);
if (token == NULL)
return (FAILURE);
while (token)
{
data->arg[i++] =  token;
if (i + 2 >= size)
{
n_size = size * 2;
data->arg = _realloc(data->arg, size * sizeof(char *),
n_size * sizeof(char *));
if (data->arg == NULL)
return (FAILURE);
size = n_size;
}
token = strtok(NULL, DELIMITER);
}
data->arg[i] = NULL;
return (0);
}

#undef DELIMITER
#define DELIMITER ":"

/**
* _parseline - parses arguments to commands
* @data: pointer to struct of data
*
* Return: if success a positive number and if failed a negative number
*/

int _parseline(s_t *data)
{
if (path_f(data) > 0)
return (SUCCESS);
if (is_bltin(data) > 0)
{
if (handle_b(data) < 0)
return (FAILURE);
return (NEUTRAL);
}
short_f(data);
return (SUCCESS);
}
#undef DELIMITER
/**
* _cmd - process command and execute process
* @data: pointer to struct of data
*
* Return: if success a postive number and if failed a negative number
*/

int _cmd(s_t *data)
{
pid_t pid;
int status;

pid = fork();
if (pid == 0)
{
signal(SIGINT, SIG_DFL);
if (execve(data->cmd, data->arg, environ) < 0)
data->error = _strdup("not found\n");
return (FAILURE);
}
else
{
waitpid(pid, &status, WUNTRACED);
}
return (0);
}
