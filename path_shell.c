#include "shell.h"

/**
 * _strcpy - Copy the string from source to destination
 * @src: source
 * @dest: destination
 * Return: pointer to the destination
 */
char *_strcpy(char *dest, char *src)
{
int i;
int len = 0;

while (*(src + len) != '\0')
{
len++;
}

for (i = 0; i <= len; i++)
{
*(dest + i) = *(src + i);
}
return (dest);
}

/**
 * executepath - access PATH
 * @p: directory to access
 * @tokens: array to check
 */
void executepath(char *p, char **tokens)
{
int status, len, len2;
pid_t child;
char *newp = NULL;

for (len = 0; *(p + len) != '\0'; len++)
;
for (len2 = 0; tokens[0][len2] != '\0'; len2++)
;
newp = malloc(sizeof(char) * (len + len2 + 2));
_strcpy(newp, p);
_strcat(newp, "/");
_strcat(newp, tokens[0]);
newp[(len + len2 + 1)] = '\0';

child = fork();

if (child == 0)
{
if (access(newp, X_OK) == 0)
{
execve(newp, tokens, environ);
}
}
else
{
while (waitpid(-1, &status, 0) != child)
;
}
if (status == 0)
errno = 0;
free(newp);
}

/**
 * searchpath - search PATH
 * @p: PATH to search
 * @tokens: tokens Array
 * Return: 0 if success
 */

int searchpath(char *p, char **tokens)
{
struct dirent *de;
int reached = 0, onpath = -1;

p = strtok(p, ":");
while (p != NULL && reached != 1)
{
DIR *dr = opendir(p);
if (dr == NULL)
{
/* not found */
return (0);
}
while ((de = readdir(dr)) != NULL)

{
if (_strcmp(de->d_name, tokens[0]) == 0)
{
executepath(p, tokens);
onpath = 0;
reached = 1;
break;
}
}
closedir(dr);
if (reached == 0)
p = strtok(NULL, ":");
/* continue to look through dir until something is/isn't found*/
}
return (onpath);
}

/**
 * findonpath - Find the PATH using the findonpath function.
 * @tokens: Token to be passed along to PATH.
 *
 * Return: 0 on success
 */

int findonpath(char **tokens)
{
int i = 0, onpath;
char *p = NULL;
char *path = NULL;

for (i = 0; environ[i] != NULL; i++)
{
if (_strncmp("PATH=", environ[i], 5) == 0)

{
path = _strdup(environ[i]);
strtok(path, "=");
p = strtok(NULL, "=");
onpath = searchpath(p, tokens);
break;
}
}
free(path);
return (onpath);
}
