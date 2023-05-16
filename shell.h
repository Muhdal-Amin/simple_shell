#ifndef main_h
#define main_h

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

typedef struct funcs {
	char *command;
	char func; //int (*f)... we will make an array of pointers to the functions (i.e ls, pwd, exit, etc...)
} functions;


int _putchar(char c);
int _strlen(char *str);
int _strcmp(char *str1, char *str2);






#endif
