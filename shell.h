#ifndef SHELL_H
#define SHELL_H

/* ---- library ---- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
  * ShellInfo - main
  * @last_exit_status: Holds the exit status of the last executed command
  */
typedef struct
{
	int last_exit_status;
} ShellInfo;

extern char **environ;


#define WHITESPACE_DELIM " \t\r\n\a\""


/* ---- main functions ---- */
void shell_repl(ShellInfo *info);
void batch_mode(ShellInfo *info);
/* ---- referenced functions ---- */
char *my_getline(void);

char **my_strtok(char *input);

int builtin_check(const char *command);
int builtin_execute(const char *command, char **arg, ShellInfo *info);

int expand_variables(char **arg);
int track_command(char **arg, ShellInfo *info);

int _pid(char **arg, ShellInfo *info);

char *standard_stream(void);

int my_own_exit(char **arg);
int my_own_cd(char **arg);
int my_own_env(char **arg);
int my_own_setenv(char **arg);
int my_own_unsetenv(char **arg);
int my_own_help(char **arg);

#endif /* SHELL_H */
