#include "shell.h"

/**
 * _strcmp - Compare two strings using _strcmp function.
 *
 * @s1: First string.
 * @s2: Second string.
 *
 * Return: 0 on success, -1 on failure.
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 || *s2)
{
if (*s1 == *s2)
{
s1++;
s2++;
}
else
return (-1);
}
return (0);
}

/**
 * _strncmp - Compare strings.
 *
 * @s1: First string to compare.
 * @s2: Second string to compare.
 * @len: Length of string to compare.
 *
 * Return: 0 on success.
 */
int _strncmp(char *s1, char *s2, int len)
{
for (; *s1 && *s2 && len >= 0; len--)
{
if (*s1 == *s2)
{
s1++;
s2++;
}
else
return (-1);
}
return (0);
}

/**
 * _strcat - Concatenate two strings using _strcat function.
 * @dest: Destination string.
 * @src: Source string.
 *
 * Return: pointer to dest.
 */
char *_strcat(char *dest, char *src)
{
int i;
int len1 = 0;
int len2 = 0;

while (*(src + len1) != '\0')
{
len1++;
}

while (*(dest + len2) != '\0')
{
len2++;
}

for (i = 0; i <= len1; i++)
{
*(dest + (len2 + i)) = *(src + i);
}
return (dest);
}

/**
 * _strdup - Duplicate a string
 * @str: the string to duplicate
 *
 * Return: a pointer to a duplicate
 */
char *_strdup(char *str)
{
char *ar;
unsigned int i, size;

if (str == NULL)
return (NULL);
for (size = 0; *(str + size) != '\0'; size++)
;
ar = malloc((size + 1) * sizeof(char));
if (ar == NULL)
return (NULL);
for (i = 0; str[i] != '\0'; i++)
{
ar[i] = str[i];
}
ar[i] = '\0';
return (ar);
}

/**
 * numcount - Count the number of tokens
 * @line: Input for calculating the number of tokens.
 *
 * Return: Number of tokens to be created.
 */
int numcount(char *line)
{
int num_tokens = 0, i, check = 1;

for (i = 0; line[i]; i++)
{
if (line[i] == ' ' || line[i] == 10 || line[i] == '\t')
check = 1;
else if (check == 1)
{
check = 0;
++num_tokens;
}
}
return (num_tokens);
}
