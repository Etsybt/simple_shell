#include "shell.h"

/**
  * execve_arg - mainf fun
  * @arg: commands
  * Return: 1 on success
  */

int execve_arg(char **arg)
{
	char *built_ins_implement[] = {
		"exit",
		"cd",
		"env",
		"help"
	};

	int (*built_ins[])(char **) = {
		&my_own_exit,
		&my_own_cd,
		&my_own_env,
		&my_own_help
	};

	unsigned int n = 0;

	if (arg[0] == NULL)
	{
		return (-1);
	}

	for (; n < sizeof(built_ins_implement) / sizeof(char *); n++)
	{
		if (strcmp(arg[0], built_ins_implement[n]) == 0)
		{
			return ((*built_ins[n])(arg));
		}
	}
	return (_pid(arg));
}
