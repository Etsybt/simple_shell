#include "shell.h"

/**
  * shell_repl - interactive shell mode
  * @info: info
  * Return: void
  */
void shell_repl(ShellInfo *info)
{
	char *input;
	char **arg;
	int status;
	int i;

	while (1)
	{
		_putstr("Nouha_SHELL$ ");

		input = my_getline();

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

		for (i = 0; arg[i] != NULL; i++)
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
