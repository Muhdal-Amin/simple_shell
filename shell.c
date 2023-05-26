#include "shell.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of strings of arguements
 *
 * Return: loop that ends on user exit command
 */

int main(int ac, char **av, char *env[])
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

	(void)ac, (void)env;

	while (1)
	{
		if ((isatty(STDIN_FILENO) == 1) && (isatty (STDOUT_FILENO) == 1))
			write(STDOUT_FILENO, prompt, 2);

		read_count = getline(&lineptr, &n, stdin);

		if (read_count == -1)
			exit(0);
		if (read_count == 1)	/* checks if input is empty */
			continue;
		
		if (cmpexit(lineptr, "exit") == 0)	/* checks for exit command */
		{
			break;
		}	
		if (cmpenv(lineptr, "env") == 0)	/* checks for env command */
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
			continue;
		}

		lineptr_dup = malloc(sizeof(char) * (read_count));
		if (!lineptr_dup)
		{
			perror("Memory Allocation Error");
			return (-1);
		}

		_strcpy(lineptr_dup, lineptr);	/* duplicate input to prevent loss of string through strtok */

		tok_count = 0;
		token = strtok(lineptr, delim);
		test = token;
		if (get_path(test) == NULL)	/* test if command exists */
		{
			_puts("sh: 1: ");
			_puts(test);
			_puts(": not found\n");
			continue;
		} 
		else
		{

		while (token)
		{
			tok_count++;
			token = strtok(NULL, delim);
		}
		tok_count++;

		av = malloc(sizeof(char *) * tok_count);

		token = strtok(lineptr_dup, delim);
		for (i = 0; token != NULL; i++)		/* tokenization */
		{
			av[i] = malloc(sizeof(char) * _strlen(token));
			_strcpy(av[i], token);
			token = strtok(NULL, delim);
		}
		av[i] = NULL;

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Forking Error");
			return (-1);
		}
		if (child_pid == 0)
		{
			execve_cmd(av);
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
	
	return (EXIT_SUCCESS);
	
}
