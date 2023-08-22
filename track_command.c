#include "shell.h"
/**
  * track_command - main func
  * @arg: commands
  * @info: for the echo $?
  * Return: 1 on success
  */
int track_command(char **arg, ShellInfo *info)
{
	int i = 0;

	if (arg[0] == NULL)
	{
		return (-1);
	}

	for (; arg[i] != NULL; i++)
	{
		if (strcmp(arg[i], "$$") == 0)
		{
			free(arg[i]);
			arg[i] = malloc(10);
			snprintf(arg[i], 10, "%d", getpid());
		}
	}

	expand_variables(arg);

	if (builtin_check(arg[0]))
	{
		return (builtin_execute(arg[0], arg, info));
	}
	return (_pid(arg, info));
}
