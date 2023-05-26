#include "shell.h"

/**
 * my_putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int my_putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - writes the string *str to stdout
 * @str: the string to print
 *
 * Return: void
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		my_putchar(str[i]);

}
