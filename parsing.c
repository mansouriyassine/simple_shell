#include "shell.h"

/**
 * parse - Tokenize user input.
 * @line: Input for parsing.
 * @num_tokens: Count of tokens.
 * @argv: arguments array.
 * @cmdcount: Number of entered commands.
 * Return: return 0 if sucess
 */
int parse(char *line, int num_tokens, char **argv, int cmdcount)
{
int i = 0, bltin, exval = 0;
char *p = NULL, *newline = NULL, **array = NULL, **ar = NULL;
char *del = " \t\r\n\f\v";

array = malloc(sizeof(char *) * num_tokens);
newline = _strdup(line);
p = strtok(newline, del);
if (p == NULL)
{
myfree(line, ar, newline, array);
return (0);
}
for (; p != NULL; p = strtok(NULL, del))
array[i++] = p;
ar = malloc(sizeof(char *) * (num_tokens + 1));
for (i = 0; i < num_tokens; i++)
ar[i] = _strdup(array[i]);
ar[i] = NULL;
bltin = checkbltin(line, ar, newline, array);
if (bltin == 0)
exval = exe(line, ar, newline, array, argv, cmdcount);
myfree(line, ar, newline, array);
return (exval);
}

/**
 * myfree - Free memory using myfree function.
 * @line: Line memory to be freed.
 * @ar: Array memory to be freed.
 * @newline: Line memory to be freed.
 * @array: Array memory to be freed.
 */
void myfree(char *line, char **ar, char *newline, char **array)
{
int i = 0;
if (ar != NULL)
{
while (ar[i] != NULL)
{
free(ar[i]);
i++;
}
free(ar);
}
if (newline != NULL)
free(newline);
if (line != NULL)
free(line);
if (array != NULL)
free(array);
}
