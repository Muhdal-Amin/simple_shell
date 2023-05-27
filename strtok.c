#include "shell.h"

/**
 * _strtok - function that splits a string into tokens.
 * @str: input string.
 * @delim: character indicating where to split the string str.
 * Return: pointer to the split token.
 */
char *_strtok(char *str, char *delim)
{
	static char *reserve;
	char *rtn;

	if (str == NULL)
		str = reserve;
	if (str == NULL)
		return (NULL);

	while (1)
	{
		if (*str == *delim)
		{
			str++;
			continue;
		}
		if (*str == '\0')
			return (NULL);
		break;
	}
	/*abd sdfsdf ssfs sfsd*/
	rtn = str;

	while (1)
	{
		if (*str == *delim)
		{
			/*abd'\0'sdfsdf ssfs sfsd*/
			*str = '\0';
			reserve = str + 1;
			return (rtn);
		}
		if (*str ==  '\0')
		{
			reserve = str;
			return (rtn);
		}
		str++;
	}
}
