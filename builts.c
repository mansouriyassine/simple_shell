#include "shell.h"
/**
 * checkbltin - Check if the entered command is a built-in.
 * @line: User input.
 * @ar: Array for execve.
 * @newline: Duplicate of the input line.
 * @array: Tokens for checking.
 * Return: Varies based on the presence of the built-in command.
 */
int checkbltin(char *line, char **ar, char *newline, char **array)
{
int i = 0;

if (_strcmp(ar[0], "exit") == 0)
{
myfree(line, ar, newline, array);
_exit(errno);
}
if (_strcmp(ar[0], "env") == 0)
{
for (i = 0; environ[i] != NULL; i++)
{
_puts(environ[i]);
write(1, "\n", 1);
}
return (2);
}
if (_strcmp(ar[0], "cd") == 0)
{
changedir(ar);
return (2);
}
return (0);
}
/**
 * changedir - Change the current directory to the specified directory.
 * @ar: Directory path to change to (or none).
 */
void changedir(char **ar)
{
int i = 0;
char *homeval = NULL, *home = NULL;

if (ar[1] == NULL)
{ /* if cd is by itself */
for (i = 0; environ[i] != NULL; i++)
{
if (_strncmp("HOME=", environ[i], 5) == 0)
{
home = _strdup(environ[i]);
strtok(home, "=");
homeval = strtok(NULL, "=");
break;
}
}
}
else
homeval = ar[1];
chdir(homeval);
free(home);
}
