#include "shell.h"

void shell_repl(void)
{
	char *input;
	char **arg;
	int status;
	int i = 0;

	while (1) {
		printf("Nouha_SHELL$ ");

		input = my_getline();

		if (!input) {
			perror("Error reading input");
			exit(EXIT_FAILURE);
		}
		arg = my_strtok(input);

		if (!arg) {
			perror("Error parsing input");
			free(input);
			exit(EXIT_FAILURE);
		}
		status = track_command(arg);

		free(input);

		for (; arg[i] != NULL; i++) {
			free(arg[i]);
		}
		free(arg);

		if (status >= 0) {
			exit(status);
		}
	}
}
