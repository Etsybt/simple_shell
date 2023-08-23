#include "shell.h"
/**
  * my_own_unsetenv - unsets the env variable
  * @arg: arg
  * Return: 1 on success
  */
int my_own_unsetenv(char **arg)
{
	if (arg[1] == NULL)
	{
		perror("Usage: unsetenv VARIABLE");
		return (-1);
	}
	if (unsetenv(arg[1]) != 0)
	{
		perror("unsetenv");
	}
	return (-1);
}
