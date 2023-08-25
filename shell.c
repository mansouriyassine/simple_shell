#include "shell.h"

/**
 * main - Entry point of the shell
 * @argc: Argument count.
 * @argv: Arguments Array.
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
size_t bufsize = 0;
char *line = NULL;
int i, num_tokens = 0, cmdcount = 1, shell_interaction;

signal(SIGINT, SIG_IGN);
shell_interaction = isatty(STDIN_FILENO);
if (shell_interaction == 0 && argc == 1)
{
while (getline(&line, &bufsize, stdin) > 0)
{
num_tokens = numcount(line);
parse(line, num_tokens, argv, cmdcount);
line = NULL;
}
free(line);
return (0);
}
while (shell_interaction)
{
write(1, "($) ", 4);
num_tokens = 0;
i = getline(&line, &bufsize, stdin);
if (i < 0)
{
free(line);
write(1, "\n", 1);
break;
}
num_tokens = numcount(line);
parse(line, num_tokens, argv, cmdcount);
cmdcount++;
line = NULL;
}
return (0);
}
