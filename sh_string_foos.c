#include "shell.h"

/**
 * _strcat - ncatenates two strings
 * @dst: Destination string
 * @src: source string
 *
 * Return: Always 0
 */

char *_strcat(char *dst, char *src)
{
int i, j = 0;

for (i = 0; dst[i] != '\0'; i++)
{
}
for (j = 0; src[j] != '\0'; j++)
{
dst[i] = src[j];
i++;
}
dst[i] = '\0';
return (dst);
}

/**
 * _strcmp - Compares two strings
 * @s1: a string
 * @s2: Another string
 *
 * Return: multiple returns
 */

int _strcmp(char *s1, char *s2)
{
int i = 0;
int val;

while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i])
i++;
val = s1[i] - s2[i];
return (val);
}

/**
 * _strlen - gets the size of a string
 * @s: the string to measure
 *
 * Return: the length of the string
 */

int _strlen(char *s)
{
int i;

for (i = 0; s[i] != 0; i++)
;
return (i);
}

/**
 *_strncmp -  function that compares two strings.
*@s1: string one
*@s2: string two
*@n: number of characters
*
* Return: diference
*/

size_t _strncmp(char *s1, char *s2, size_t n)
{
size_t i, j;

for (j = 0; s1[j] != '\0' && j < n; j++)
{
i = s1[j] - s2[j];

if (i != 0)
{
return (i);
}
}
return (0);
}

/**
 * _strcpy - copies the string pointed to by src into dest
 * @dst: destination of the copy
 * @src: source of the copy
 *
 * Return: char pointer to dest
 */

char *_strcpy(char *dst, char *src)
{
int i = 0;

for (i = 0; src[i] != '\0'; i++)
{
dst[i] = src[i];
}
dst[i + 1] = 0;
return (dst);
}
