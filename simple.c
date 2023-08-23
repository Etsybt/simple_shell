#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 100

int main()
{
	char input[MAX_INPUT_LENGTH];
	char *args[2];
	pid_t pid;
	int status;

	while (1)
	{
		printf("#cisfun$ ");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		input[strlen(input) - 1] = '\0';

		if (strcmp(input, "exit") == 0)
		{
			break;
		}

		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		} else if (pid == 0)
		{
			args[0] = input;
			args[1] = NULL;
			
			if (execve(args[0], args, NULL) == -1) {
				perror("execve");
				exit(EXIT_FAILURE);
			}
		} else {
			waitpid(pid, &status, 0);
		}
	}
	return 0;
}

