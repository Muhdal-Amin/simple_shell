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


int my_putchar(char c);
void _puts(char *str);

int _strlen(const char *str);
int _strcmp(char *str1, char *str2);
int _strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(const char *str);
int _strncmp(const char *s1, const char *s2, size_t n);

int cmpexit(char *s1, char *s2);
int cmpenv(char *s1, char *s2);

void execve_cmd(char **av);
char *get_path(char *command);
int stat(const char *pathname, struct stat *statbuf);
char **line_tokenizer(char *lineptr, ssize_t read_count);
char *_getenv(const char *name);





#endif
