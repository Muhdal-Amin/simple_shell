#include "shell.h"

/**
 * handle_env - function that handles the env builtin command.
 * Return: Void
 */
void handle_env(void)
{
	int x = 0;

	while (environ[x] != NULL)
	{
		write(STDOUT_FILENO, environ[x], _strlen(environ[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
	printf("Done\n");
}

/**
 * cmpexit - Function that checks if the user inputted the exit command.
 * @s1:first string
 * @s2: second string
 * Return: 1 on success and 0 on failure.
 */

int cmpexit(char *s1, char *s2)
{
	int i = 0;

	for (; (*s2 != '\0' && *s1 != '\0') && *s1 == *s2; s1++)
	{
		if (i == 3)
			break;
		i++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * cmpenv - Function that checks if user inputted the env command.
 * @s1: first string
 * @s2: second string
 * Return: 1 on success and 0 on failure.
 */

int cmpenv(char *s1, char *s2)
{
	int i = 0;

	for (; (*s2 != '\0' && *s1 != '\0') && *s1 == *s2; s1++)
	{
		if (i == 2)
			break;
		i++;
		s2++;
	}
	return (*s1 - *s2);
}
