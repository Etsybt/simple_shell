#include "shell.h"

/**
  * no_interactive - the non interactive varsion of our shell
  * Return: void
  */

void no_interactive(void)
{
	char *input;
	char **arg;
	int status = -1;

	do {
		input = standard_stream();
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
