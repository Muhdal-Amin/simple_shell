#include "shell.h"


/**
 * line_tokenizer - processes the input text into commands and arguments
 * @lineptr : string containing input text
 * @read_count : number of characters read by getline() function
 *
 * Return: pointer to array of tokenized text
 */
char **line_tokenizer(char *lineptr, ssize_t read_count)
{
	int i = 0;
	int tok_count;
	char *lineptr_dup = NULL;
	char *token;
	const char *delim = " \n";
	char **argv;

	lineptr_dup = malloc(sizeof(char) * read_count);
	if (!lineptr_dup)
	{
		perror("Memory Allocation Error");
		return (NULL);
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


	return (argv);
}
