#include "shell.h"
/**
  * _pid - make a new process
  * @arg: commands
  * @info: for the echo $?
  * Return: 1 on success
  */
int _pid(char **arg, ShellInfo *info)
{
	pid_t child_pid;
	int child_status;

	child_pid = fork();

	if (child_pid == 0)
	{
		/* if (execvp(arg[0], arg) == -1)
		{
			perror(arg[0]);
		}
		exit(EXIT_FAILURE); */
		char *executable_path = find_executable(arg[0]);
		if (executable_path == NULL)
		{
			fprintf(stderr, "Executable '%s' not found.\n", arg[0]);
			exit(EXIT_FAILURE);
		}
		if (execve(executable_path, arg, environ) == -1)
		{
			perror(arg[0]);
		}
		exit(EXIT_FAILURE);
	}
	else if (child_pid < 0)
	{
		perror(arg[0]);
	}
	else
	{
		do {
			waitpid(child_pid, &child_status, WUNTRACED);
		} while (!WIFEXITED(child_status) && !WIFSIGNALED(child_status));

		info->last_exit_status = WEXITSTATUS(child_status);
	}
	return (-1);
}
