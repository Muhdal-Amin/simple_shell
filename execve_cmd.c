#include "shell.h"

void execve_cmd(char **argv)
{
	char *command = NULL;
	char *command_path = NULL;

	if (argv)
	{
		command = argv[0];
