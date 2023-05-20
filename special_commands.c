#include "shell.h"

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
