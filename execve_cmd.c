#include "shell.h"

/**
 * execve_cmd - executes a given command
 * @av : array containing tokenized input text
 * Return: void
 */
void execve_cmd(char **av)
{
	char **env = environ;
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Forking Error");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(av[0], av, env) == -1)
			perror(av[0]);
		exit(0);
	}
	else
	{
		wait(&status);
	}
}
