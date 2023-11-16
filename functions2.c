#include "shell.h"

/**
 * _strcpy - copies a string from source to destination
 * @s: string source
 * @d: string destination
 *
 * Return: pointer to d
 */
char *_strcpy(char *d, char *s)
{
int i;

for (i = 0; s[i] != '\0'; i++)
{
d[i] = s[i];
}
d[i] = '\0';
return (d);
}
/**
 * _isalpha - checks if the input is a letter
 * @c: the character to be checked
 *
 * Return: 1 if letter, 0 if not
 */
int _isalpha(int c)
{
if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
{
return (SUCCESS);
}
return (FAILURE);
}
