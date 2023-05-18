#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @dest - string to concatenate to
 * @src - source of string
 *
 * Return: final string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	if (!dest && !src)
		return (NULL);

	char *result = dest;

	while (result[i] != '\0')
		i++;

	while (src[j] != '\0')
	{
		result[i] = src[j];
		i++;
		j++;
	}
	result[i] = '\0';

	dest = result;

	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str - string to be duplicated
 *
 * Return: pointer to duplicate string
 */
char *_strdup(const char *str)
{
	int i = 0;
	char *result;

	if (!str)
		return (NULL);

	while (str[i] != '\0')
		i++;

	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		result[i] = str[i];

	result[i] = '\0';

	return (result);
}
