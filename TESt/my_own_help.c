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

	_putstr("\n-the manual for the built-in commands-\n");
	_putstr(" ");
	_putstr(built_ins_implement[0]);
	_putstr(" ---> EXIT the program. <log out>\n");
	_putstr(" ");
	_putstr(built_ins_implement[1]);
	_putstr(" ---> change directories.\n");
	_putstr(" ");
	_putstr(built_ins_implement[2]);
	_putstr(" ---> displays the environment.\n");
	_putstr(" ");
	_putstr(built_ins_implement[3]);
	_putstr(" ---> sets a new environment variable.\n");
	_putstr(" ");
	_putstr(built_ins_implement[4]);
	_putstr(" ---> removes an environment variable.\n");
	_putstr(" ");
	_putstr(built_ins_implement[5]);
	_putstr(" ---> displays the program manual\n");
	_putstr("\n\nfor other commands use man + command_name.\n\n");

	return (-1);
}
