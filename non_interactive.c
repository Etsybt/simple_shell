#include "shell.h"

/**
  * no_interactive - the non interactive varsion of our shell
  * Return: void
  */

void no_interactive(void)
{
	char *input;
	char **arg;
	int i = 0, status = -1;

	do {
		input = standard_stream();
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
