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

	while (environ[n] != NULL)
	{
		size_t length = strlen(environ[n]);
		ssize_t bytes = write(STDOUT_FILENO, environ[n], length);

		if (bytes != (ssize_t)length)
		{
			perror("my_own_env: ERROR");
			return (-1);
		}

		write(STDOUT_FILENO, "\n", 1);
		n++;
	}
	return (-1);
}
