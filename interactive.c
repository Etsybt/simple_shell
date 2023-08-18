#include "shell.h"

/**
  * interactive - the interactive version of our shell
  * Return: void
  */

void interactive(void)
{
	char *input;
	char **arg;
	int status = -1;

	while (1)
	{
		printf("Nouha_SHELL$ ");

		input = _getline();

		if (!input)
			break;

		arg = _strtok(input);

		if (!arg)
		{
			free(input);
			continue;
		}
		status = execve_arg(arg);

		free(input);
		free(arg);

		if (status >= 0)
		{
			exit(status);
		}
	}
}
