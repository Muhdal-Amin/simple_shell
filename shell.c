#include "shell.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of strings of arguements
 *
 * Return: loop that ends on user exit command
 */

int main(int argc, char **argv)
{
	int i = 0;
	int tok_count;
	int status;
	size_t n = 0;
	ssize_t read_count;
	char *prompt = "$ ";
	char *lineptr = NULL, *lineptr_dup = NULL;
	char *token;
	const char *delim = " \n";
	pid_t child_pid;

	(void)argc;

	while (1)
	{
		_puts(prompt);

		read_count = getline(&lineptr, &n, stdin);
		if (read_count == -1)
		{
			_puts("Error reading command\n");
			return (-1);
		}

		lineptr_dup = malloc(sizeof(char) * read_count);
		if (!lineptr_dup)
		{
			perror("Memory Allocation Error");
			return (-1);
		}
		_strcpy(lineptr_dup, lineptr);
		
		tok_count = 0;
		token = strtok(lineptr, delim);
		while (token)
		{
			tok_count++;
			token = strtok(NULL, delim);
		}
		tok_count++;

		argv = malloc(sizeof(char *) * tok_count);
		token = strtok(lineptr_dup, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * _strlen(token));
			_strcpy(argv[i], token);

			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Forking Error");
			return (-1);
		}
		if (child_pid == 0)
		{
			execve_cmd(argv);
		}
		else
			wait(&status);
	}

	free(lineptr);
	free(lineptr_dup);
	free(argv);

	return (0);

}
