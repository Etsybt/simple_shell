#include "shell.h"

/**
  * my_own_env - custom env
  * @arg: arg
  * Return: 1 on success
  */

int my_own_env(char **arg)
{
	int n = 0;
	(void)(**arg);

	while (environ[n])
	{
		write(STDOUT_FILENO, environ[n], my_strlen(environ[n]));
		write(STDOUT_FILENO, "\n", 1);
		n++;
	}
	return (-1);
}
