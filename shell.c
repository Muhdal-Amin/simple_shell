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
	int tok_count = 0;
	int status;
	size_t n = 0;
	ssize_t read_count = 0;
	char *prompt = "$ ";
	char *lineptr = NULL, *lineptr_dup = NULL;
	char *token = NULL;
	const char *delim = " :\n\t\r\f\v";
	pid_t child_pid;
	char *test = NULL;

	(void)argc;

	while (1)
	{
		if ((isatty(STDIN_FILENO) == 1) && (isatty (STDOUT_FILENO) == 1))
			write(STDOUT_FILENO, prompt, 2);

		read_count = getline(&lineptr, &n, stdin);

		if (read_count == -1)
		{
			break;
		}
		if (read_count == 1)
		{
			continue;
		}
		
		if (cmpexit(lineptr, "exit") == 0)
		{
			break;
		}
		if (cmpenv(lineptr, "env") == 0)
		{
			if (environ != NULL)
			{
				char **env = environ;

				while (*env != NULL)
				{
					_puts(*env);
					_puts("\n");
					env++;
				}
			}
		}
		lineptr_dup = malloc(sizeof(char) * (read_count));
		if (!lineptr_dup)
		{
			perror("Memory Allocation Error");
			return (-1);
		}
		_strcpy(lineptr_dup, lineptr);
		tok_count = 0;
		token = strtok(lineptr, delim);
		test = token;
		if (get_path(test) == NULL)
		{
			_puts(test);
			_puts(": command not found\n");
			continue;
		} else {
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
			exit(0);
		}
		else
		{
			wait(&status);
		}
		}

	}	
	free(lineptr);
	free(lineptr_dup);
	free(argv);
	
	return (EXIT_SUCCESS);
	
}
