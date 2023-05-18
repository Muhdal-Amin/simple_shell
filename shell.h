#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;

char *show_input(void);
void prompt(void);


int _putchar(char c);
int _puts(char *str);
int _strlen(char *str);
int _strcmp(char *str1, char *str2);
int _strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(const char *str);






#endif
