#include "shell.h"

/**
  * interactive - the interactive version of our shell
  * Return: void
  */

void interactive(void)
{
	char *input;
	char **arg;
	int i = 0, status = -1;

	do {
		printf("Nouha_SHELL$ ");
		input = my_getline();
		arg = my_strtok(input);
		status = execve_arg(arg);

		free(input);
		for (; arg[i] != NULL; i++)
			free(arg[i]);
		free(arg);

		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}
