#include "shell.h"

/**
 * _puts - Write a string to standard output
 * @str: String to be written.
 */
void _puts(char *str)
{
while (*str  != '\0')
{
write(1, str, 1);
str++;
}
}

/**
 * prstr - Print strings from arguments using prstr function.
 * @args: argu pointer
 *
 * Return: Count of printed string elements.
 */
int prstr(va_list *args)
{
int x = 0;
char *ar;

ar = va_arg(*args, char *);
while (*ar != '\0')
{
_putchar(*ar);
x++;
ar++;
}
return (x);
}

/**
 * _putchar - Output the character c to standard
 * @c: The character to be printed.
 *
 * Return: 1 on success, -1 on error with appropriate errno.
 */
int _putchar(char c)
{
return (write(2, &c, 1));
}
