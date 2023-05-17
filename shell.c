#include "main.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of strings of arguements
 *
 * Return: loop that ends on user exit command
 */

int main(int argc, char **argv)
{
	(void)argv;
	(void)argc;

	signal(SIGINT, controlC);
	prompt();
	return (0);

}
