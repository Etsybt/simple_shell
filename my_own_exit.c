#include "shell.h"

/**
  * my_own_exit - custom exit command
  * @arg: arg
  * Return: 0
 */

int my_own_exit(char **arg)
{
	if (arg[1] != NULL)
	{
		int exit_status = atoi(arg[1]);

		return (exit_status);
	}
	else
	{
		return (0);
	}
}
