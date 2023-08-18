#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


extern char **environ;


#define WHITESPACE_DELIM " \t\r\n\a"




void interactive(void);
void no_interactive(void);


char *_getline(void);
char **_strtok(char *input);
int execve_arg(char **arg);
char *standard_stream(void);

int pid(char **arg);

int my_own_exit(char **arg);
int my_own_cd(char **arg);
int my_own_env(char **arg);
int my_own_help(char **arg);


#endif
