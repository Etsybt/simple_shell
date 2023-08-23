#ifndef SHELL_H
#define SHELL_H

/* ---- library ---- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/stat.h>


#define MAX_PATH_LENGTH 4096

/**
  * ShellInfo - main
  * @last_exit_status: Holds the exit status of the last executed command
  */
typedef struct
{
	int last_exit_status;
} ShellInfo;

extern char **environ;


struct AllocatedTokens
{
	char **tokens;
	size_t count;
};


#define WHITESPACE_DELIM " \t\r\n\a\""
void *my_own_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


/* ---- main functions ---- */
void shell_repl(ShellInfo *info);
void batch_mode(ShellInfo *info);
/* ---- referenced functions ---- */

int my_getchar(void);

char *my_getline(void);

char *my_strchr(const char *str, int c);
char *my_strncpy(char *dest, const char *src, size_t n);
char *my_strcpy(char *dest, char *src);

/* ---- my own strtok -----*/
char **allocate_initial_memory(size_t size);
char *my_realloc(char **str, size_t *size, size_t new_size);
void add_token(char **str, size_t *n, size_t *size,
		const char *start, const char *end);
char **my_strtok(char *input);



int my_strcmp(const char *s1, const char *s2);

void *my_memcpy(void *dest, const void *src, size_t n);
size_t my_strlen(const char *str);
char *my_strdup(const char *str);

int my_atoi(const char *str);

int _putchar(char c);
void _putstr(const char *str);

void int_to_str(int num, char *str);

int builtin_check(const char *command);
int builtin_execute(const char *command, char **arg, ShellInfo *info);

int expand_variables(char **arg);
int track_command(char **arg, ShellInfo *info);

char *find_executable(const char *file);

int _pid(char **arg, ShellInfo *info);

char *standard_stream(void);

int my_own_exit(char **arg);
int my_own_cd(char **arg);
int my_own_env(char **arg);
int my_own_setenv(char **arg);
int my_own_unsetenv(char **arg);
int my_own_help(char **arg);

#endif /* SHELL_H */
