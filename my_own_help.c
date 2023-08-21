#include "shell.h"

/**
  * my_own_help - custom help
  * @arg: arg
  * Return: 1 on success
  */

int my_own_help(char **arg)
{
	char *built_ins_implement[] = {
		"exit",
		"cd",
		"env",
		"setenv",
		"unsetenv",
		"help"
	};
	(void)(**arg);
	printf("\n-the manual for the built-in commands-\n");
	printf(" %s ---> EXIT the program. <log out>\n", built_ins_implement[0]);
	printf(" %s ---> change directories.\n", built_ins_implement[1]);
	printf(" %s ---> displays the environment.\n", built_ins_implement[2]);
	printf(" %s ---> sets a new environment variable.\n", built_ins_implement[3]);
	printf(" %s ---> removes an environment variable.\n", built_ins_implement[4]);
	printf(" %s ---> displays the program manual\n", built_ins_implement[5]);

	printf("\n\nfor other commands use man + command_name.\n\n");
	return (-1);
}
