#include "shell.h"
/**
 * builtin_check - check if a command is a built-in command
 * @command: command to check
 * Return: 1 if it's a built-in, 0 otherwise
 */
int builtin_check(const char *command)
{
	char *built_ins_implement[] = {
		"exit",
		"cd",
		"env",
		"setenv",
		"unsetenv",
		"help"
	};
	unsigned int i = 0;

	for (; i < sizeof(built_ins_implement) / sizeof(char *); i++)
	{
		if (my_strcmp(command, built_ins_implement[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}
