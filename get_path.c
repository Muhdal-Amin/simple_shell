#include "shell.h"


/**
 * get_path - gets the location of a command's script file
 * @command : the command in question
 *
 * Return: pointer to string containing path
 */
char *get_path(char *command)
{
	char *path, *path_dup;
	char *path_token, *path_file;
	int cmd_length, dir_length;
	struct stat buffer;
	const char *delim = ":";

	path = _getenv("PATH");

	if (path)
	{
		path_dup = _strdup(path);
		cmd_length = _strlen(command);
		path_token = strtok(path_dup, delim);
		while (path_token)
		{
			dir_length = _strlen(path_token);
			path_file = malloc(cmd_length + dir_length + 2);

			_strcpy(path_file, path_token);
			_strcat(path_file, "/");
			_strcat(path_file, command);
			_strcat(path_file, "\0");
			if (stat(path_file, &buffer) == 0)
			{
				free(path_dup);
				return (path_file);
				free(path_file);
			} else {
				free(path_file);
				path_token = strtok(NULL, delim);
			}
		}

		if (stat(command, &buffer) == 0)
			return (command);

		return (NULL);
	}
	return (NULL);
}
