#include "shell.h"

/**
 * _getenv - Functions that gets the value of an environment variable
 * @name: the name of the environment variable
 * Return: pointer to the value of the env variable, or NULL if not found
 */

char *_getenv(const char *name)
{
	size_t name_length = _strlen(name);
	int i = 0;

	if (name_length == 0 || environ == NULL)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(name, environ[i], name_length) == 0 &&
		    environ[i][name_length] == '=')
			return (&environ[i][name_length + 1]);
	}
	return (NULL);
}
