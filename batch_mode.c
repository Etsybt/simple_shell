#include "shell.h"
/**
  * batch_mode - non interactive shell mode
  * @info: info
  * Return: void
  */
void batch_mode(ShellInfo *info)
{
	char *input;
	char **arg;
	int status;
	int i = 0;

	while (1)
	{
		input = standard_stream();
		if (!input)
		{
			perror("Error reading input");
			exit(EXIT_FAILURE);
		}
		arg = my_strtok(input);

		if (!arg)
		{
			perror("Error parsing input");
			free(input);
			exit(EXIT_FAILURE);
		}
		status = track_command(arg, info);
		free(input);

		for (; arg[i] != NULL; i++)
		{
			free(arg[i]);
		}
		free(arg);

		if (status >= 0)
		{
			exit(status);
		}
	}
}
