#include "shell.h"

/**
 * get_tokens - function that splits string into tokens.
 * @arr: cmd line string input
 * @parent: name of parent process
 * Return: void
 */

void get_tokens(char *arr, char *parent)
{
	char *argv[4096], err_msg[4096] = {'\0'}, buff[4096] = {'\0'};
	int x = 0;
	struct stat st;

	argv[x] = strtok(arr, " ");
	while (argv[x] != NULL)
	{
		x++;
		argv[x] = strtok(NULL, " ");
	}
	argv[x] = (char *) 0;

	_strcpy(&buff[0], argv[0]);

	argv[0] = get_path(buff);

	if (stat(argv[0], &st) != 0)
	{
		_strcpy(&err_msg[0], parent);
		_strcpy(&err_msg[_strlen(err_msg)], ": ");
		_strcpy(&err_msg[_strlen(err_msg)], argv[0]);
		perror(err_msg);
		x = 0;
		while (buff[x] != '\0')
		{
			buff[x] = '\0';
			x++;
		}
		return;
	}
	else
		execve_cmd(argv);
	x = 0;
	while (buff[x] != '\0')
	{
		buff[x] = '\0';
		x++;
	}
}
/**
* check_empty - function that checks if string is empty.
* @str: string input.
* Return: number of empty characters.
*/
int check_empty(char *str)
{
	int x = 0;

	while (str[x] == ' ' || str[x] == '\n')
		x++;
	return (x);
}
/**
 * main - entry point
 * @ac: number of arguments
 * @av: array of strings of arguements
 * @env: arry of environemt variables.
 * Return: loop that ends on user exit command
 */
int main(int ac, char **av, char **env)
{
	int i = 0;
	char *prompt = "$ ", lineptr[4096] = {'\0'}, *line = &lineptr[0],
	*arr[4096], *delim = "\n\t\r\f\v";

	(void)ac, (void)env;
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		write(STDOUT_FILENO, prompt, 2);
	while (read(STDIN_FILENO, line, 4096) && *line != EOF)
	{
		if (check_empty(line) != _strlen(line))
		{
			if (cmpexit(line, "exit") == 0)
				break;
			_strcpy(lineptr, line);
			arr[i] = strtok(lineptr, delim);
			while (arr[i] != NULL)
			{
				i++;
				arr[i] = strtok(NULL, delim);
			}
			arr[i] = (char *) 0;
			i = 0;
			while (arr[i] != NULL)
			{
				get_tokens(arr[i], av[0]);
				i++;
			}
			i = 0;
			while (line[i] != '\0')
			{
				line[i] = '\0';
				i++;
			}
			i = 0;
		}
		if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
			write(STDOUT_FILENO, prompt, 2);
	}
	return (EXIT_SUCCESS);
}
