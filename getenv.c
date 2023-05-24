#include "shell.h"

/**
 * _getenv - Functions that gets the value of an environment variable
 * @name: the name of the environment variable
 *
 * Return: pointer to the value of the env variable, or NULL if not found
 */

char *_getenv(const char *name)
{
<<<<<<< HEAD
	size_t name_length = strlen(name);
=======
        extern char **environ;
        size_t name_length = strlen(name);
	int i = 0;
>>>>>>> 61fe9e69701827ebbb0287651650a779514f75a1

	if (name_length == 0 || environ == NULL)
		return (NULL);

<<<<<<< HEAD
	for (int i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(name, environ[i], name_length) == 0 &&
		    environ[i][name_length] == '=')
			return (&environ[i][name_length + 1]);
	}
=======
        for (i = 0; environ[i] != NULL; i++)
        {
                if (_strncmp(name, environ[i], name_length) == 0 && environ[i][name_length] == '=')
                        return &environ[i][name_length + 1];
        }
>>>>>>> 61fe9e69701827ebbb0287651650a779514f75a1

	return (NULL);
}
