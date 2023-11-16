#include "shell.h"

/**
 * _realloc - reallocates memory block
 * @p: pointer to previous memory
 * @o_size: old size
 * @n_size: new size
 *
 * Return: pointer to newly allocated memory
 */
void *_realloc(void *p, unsigned int o_size, unsigned int n_size)
{
void *rt;

if (n_size == o_size)
return (p);
if (n_size == 0 && p)
{
free(p);
return (NULL);
}
rt = malloc(n_size);
if (rt == NULL)
return (NULL);
if (p == NULL)
{
fill(rt, '\0', n_size);
free(p);
}
else
{
_memcpy(rt, p, o_size);
free(p);
}
return (rt);
}
/**
 * _memset - fills a memory with constant byte
 * @s: pointer to memory area
 * @n: first n bytes
 * @b: constant byte
 *
 * Return: pointer to a character
 */
char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
{
s[i] = b;
}
return (s);
}
/**
 * free_d - frees data
 * @data: the data structure
 *
 * Return: if succes 0 will be returned
 * and if failed negative number will be returned
 */
int free_d(s_t *data)
{
free(data->line);
data->line = NULL;
free(data->arg);
data->arg = NULL;
free(data->cmd);
data->cmd = NULL;
free(data->error);
data->error = NULL;
return (0);
}
/**
 * _memcpy - copies memory area
 * @d: Destination of memory area
 * @s: Source  ofmemory area
 * @n: Amount of memory byte
 *
 * Return: pointer to destination
 */
char *_memcpy(char *d, char *s, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
{
d[i] = s[i];
}
return (d);
}
