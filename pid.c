#include "shell.h"

/**
  * pid - make a new process
  * @arg: commands
  * Return: 1 on success
  */

int pid(char **arg)
{
	pid_t pid;
	int child_status;

	pid = fork();

	if (pid == 0)
	{
		if (execvp(arg[0], arg) == -1)
		{
			perror("ERROR: pid");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("ERROR: fork failed");
	}
	else
	{
		waitpid(pid, &child_status, 0);

		if (WIFEXITED(child_status))
		{
			return (WEXITSTATUS(child_status));
		}
		else
		{
			printf("terminates\n");
			return (-1);
		}
	}
	return (0);
}
