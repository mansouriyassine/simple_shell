#include "shell.h"

/**
 * exe - Execute new processes.
 * @line: User input.
 * @ar: Array for execve.
 * @nln: Duplicate of the input line.
 * @arry: Tokens for checking.
 * @argv: Arguments for.
 * @flcnt: Number of failed commands.
 * Return: 0 if succ.
 */

int exe(char *line, char **ar, char *nln, char **arry, char **argv, int flcnt)
{
int status, onpath = -1;
pid_t child;
struct stat *statbuf;

statbuf = malloc(sizeof(struct stat));
if (stat(ar[0], statbuf) == -1)
{
onpath = findonpath(ar);
if (onpath == 0)
{
free(statbuf);
return (0);
}
}
child = fork();
if (child == 0)
{
if (execve(ar[0], ar, environ) == -1)
{
_printf("%s: %d: %s: not found\n", argv[0], flcnt, ar[0]);
free(statbuf);
myfree(line, ar, nln, arry);
_exit(-1); /* terminates the child */
}
}
else
{
while (waitpid(-1, &status, 0) != child)
;
}
free(statbuf);
if (status == 0)
errno = 0;
if (status == 512)
errno = 2;
if (status == 65280)
errno = 127;
return (0);
}
