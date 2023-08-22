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
void shell_repl(void);
void batch_mode(void);
/* ---- referenced functions ---- */
char *my_getline(void);
char **my_strtok(char *input);
int expand_variables(char **arg);
int track_command(char **arg);
int _pid(char **arg);

char *standard_stream(void);
int my_own_exit(char **arg);
int my_own_cd(char **arg);
int my_own_env(char **arg);
int my_own_setenv(char **arg);
int my_own_unsetenv(char **arg);
int my_own_help(char **arg);

#endif /* SHELL_H */
