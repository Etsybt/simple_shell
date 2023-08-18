#ifndef SHELL_H
#define SHELL_H

/* ---- library ---- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* ---- macros ---- */
extern char **environ;
#define WHITESPACE_DELIM " \t\r\n\a\""
/* ---- main functions ---- */
void interactive(void);
void no_interactive(void);
/* ---- referenced functions ---- */
char *_getline(void);
char **_strtok(char *input);
int execve_arg(char **arg);
int _pid(char **arg);
char *standard_stream(void);

int my_own_exit(char **arg);
int my_own_cd(char **arg);
int my_own_env(char **arg);
int my_own_help(char **arg);

#endif /* SHELL_H */
