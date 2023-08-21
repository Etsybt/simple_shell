#include "shell.h"

/**
  * track_command
  - mainf fun
  * @arg: commands
  * Return: 1 on success
  */

int track_command(char **arg)
{
	char *built_ins_implement[] = {
		"exit",
		"cd",
		"env",
		"setenv",
		"unsetenv",
		"help"
	};

	int (*built_ins[])(char **) = {
		&my_own_exit,
		&my_own_cd,
		&my_own_env,
		&my_own_setenv,
		&my_own_unsetenv,
		&my_own_help
	};

	unsigned int n = 0;
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

	for (; n < sizeof(built_ins_implement) / sizeof(char *); n++)
	{
		if (strcmp(arg[0], built_ins_implement[n]) == 0)
		{
			return ((*built_ins[n])(arg));
		}
	}
	return (_pid(arg));
}
