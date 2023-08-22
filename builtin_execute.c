#include "shell.h"
/**
 * builtin_execute - execute a built-in command
 * @command: built-in command
 * @arg: command arguments
 * @info: info
 * Return: status of the command execution
 */
int builtin_execute(const char *command, char **arg, ShellInfo *info)
{
	unsigned int i = 0;

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
	(void)(*info);

	for (; i < sizeof(built_ins) / sizeof(built_ins[0]); i++)
	{
		if (strcmp(command, built_ins_implement[i]) == 0)
		{
			return ((*built_ins[i])(arg));
		}
	}
	return (-1);
}
