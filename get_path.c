#include "shell.h"


/**
 * get_path - gets the location of a command's script file
 * @str : the command in question
 * Return: pointer to string containing path
 */
char *get_path(char *str)
{
	char path[4096] = {'\0'}, *ptr = &path[0], command[4096] = {'\0'},
	path_token[4096] = {'\0'};
	struct stat buffer;

	if (str == NULL)
		return (NULL);

	if (ptr == NULL)
		return (NULL);

	_strcpy(ptr, _getenv("PATH"));

	command[0] = '/';
	_strcpy(&command[1], str);

	_strcpy(&path_token[0], strtok(path, ":"));

	_strcpy(&path_token[_strlen(path_token)], &command[0]);

	if (stat(path_token, &buffer) == 0)
	{
		_strcpy(str, &path_token[0]);
		return (str);
	}

	while (_strcpy(&path_token[0], strtok(NULL, ":")) != -1)
	{

		_strcpy(&path_token[_strlen(path_token)], &command[0]);

		if (stat(path_token, &buffer) == 0)
		{
			_strcpy(str, &path_token[0]);
			return (str);
		}
	}
	return (str);
}

