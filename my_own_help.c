#include "shell.h"

/**
  * my_own_help - custom help
  * @arg: arg
  * Return: 1 on success
  */

int my_own_help(char **arg)
{
	const char *built_ins_implement[] = {
		"exit",
		"cd",
		"env",
		"help"
	};
	size_t num = sizeof(built_ins_implement) / sizeof(built_ins_implement[0]);
	size_t n = 0;
	(void)(**arg);

	printf("\n-help simple shell-\n");
	printf("command:\n");

	for (; n < num; n++)
	{
		printf("  -> %s\n", built_ins_implement[n]);
	}
	printf("use the man command.\n\n");
	return (-1);
}
