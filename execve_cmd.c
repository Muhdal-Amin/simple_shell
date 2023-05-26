#include "shell.h"

/**
 * execve_cmd - executes a given command
 * @argv : array containing tokenized input text
 *
 * Return: void
 */
void execve_cmd(char **argv)
{
	char *command = NULL;
	char *command_path = NULL;
	char **env = environ;

	if (argv)
	{
		command = argv[0];

		command_path = get_path(command);

		if (execve(command_path, argv, env) == -1)
			perror("execve");
	}
}
