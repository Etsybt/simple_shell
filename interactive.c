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

	do {
		printf("Nouha_SHELL$ ");
		input = _getline();
		arg = _strtok(input);
		status = execve_arg(arg);

		free(input);
		free(arg);

		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}
