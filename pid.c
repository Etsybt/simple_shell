#include "shell.h"

/**
  * _pid - make a new process
  * @arg: commands
  * Return: 1 on success
  */

int _pid(char **arg)
{
	pid_t child_pid;
	int child_status;

	child_pid = fork();

	if (child_pid == 0)
	{
		if (execvp(arg[0], arg) == -1)
		{
			perror("ERROR: child pid");
		}
		exit(EXIT_FAILURE);
	}
	else if (child_pid < 0)
	{
		perror("ERROR: forking");
	}
	else
	{
		do {
			waitpid(child_pid, &child_status, WUNTRACED);
		} while (!WIFEXITED(child_status) && !WIFSIGNALED(child_status));
	}
	return (-1);
}
