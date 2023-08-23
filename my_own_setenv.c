#include "shell.h"

/**
  * my_own_setenv - sets the env variable
  * @arg: arg
  * Return: 1 on success
  */
int my_own_setenv(char **arg)
{
	if (arg[1] == NULL || arg[2] == NULL)
	{
		perror("Usage: setenv VARIABLE VALUE");
		return (-1);
	}
	if (setenv(arg[1], arg[2], 1) != 0)
	{
		perror("setenv");
	}
	return (-1);
}
