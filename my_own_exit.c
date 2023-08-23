#include "shell.h"

/**
  * my_own_exit - custom exit command
  * @arg: arg
  * Return: 0
 */

int my_own_exit(char **arg)
{
	if (arg[1])
	{
		return (my_atoi(arg[1]));
	}
	else
	{
		return (0);
	}
}
