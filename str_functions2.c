#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @dest: string to concatenate to
 * @src: source of string
 *
 * Return: final string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i++])
		j++;

	for (i = 0; src[i]; i++)
		dest[j++] = src[i];

	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: string to be duplicated
 *
 * Return: pointer to duplicate string
 */
char *_strdup(const char *str)
{
	int i = 0;
	char *result = NULL;

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

/**
 * _strncmp - A function that compares two strings up to a specified length
 * @s1: The first string
 * @s2 The second string
 * @n: The maximum number of characters to compare
 *
 * Return: 0 if the strings are equal,-ve value if s1 < s2,+ve value if s1 > s2
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] == '\0')
			return (0);
	}

	return (0);
}
