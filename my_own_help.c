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
		"help"
	};
	unsigned int n = 0;
	(void)(**arg);

	printf("\n-help simple shell-\n");
	printf("command:\n");

	for (; n < sizeof(built_ins_implement) / sizeof(char *); n++)
	{
		printf("  -> %s\n", built_ins_implement[n]);
	}
	printf("use the man command.\n\n");
	return (-1);
}
