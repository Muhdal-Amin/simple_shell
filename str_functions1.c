#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @str : the string
 *
 * Return: length of string
 */
int _strlen(const char *str)
{
	int i = 0;

	if (!str)
		return (0);

	while (str[i] != '\0')
		i++;

	return (i);
}

/**
 * _strcmp - compares two string
 * @str1 : first string
 * @str2 : second string
 *
 * Return: 0 if they are simmilar, -1 otherwise
 */
int _strcmp(char *str1, char *str2)
{
	int i = 0;

	if (!str1 || !str2)
		return (-1);

	if (_strlen(str1) != _strlen(str2))
		return (-1);

	for (i = 0; i <= _strlen(str1); i++)
	{
		if (str1[i] != str2[i])
			return (-1);
	}

	return (0);
}

/**
 * _strcpy - copies content of a string to another string
 * @dest : the new duplicate string
 * @src : the original string
 *
 * Return: 0
 */
int _strcpy(char *dest, char *src)
{
	int i = 0;

	if (!src)
		return (-1);

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (0);
}
