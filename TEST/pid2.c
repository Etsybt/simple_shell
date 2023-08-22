#include "shell.h"

int last_exit_status = 0;
/**
  * _pid - make a new process
  * @arg: commands
  * Return: 1 on success
  */

/* int _pid(char **arg) */
int _pid(char **arg)
{
	pid_t child_pid;
	int child_status;
	char *path_env;
	char *path_copy;
	char *dir;
	char *executable_path;

	child_pid = fork();

	if (child_pid == 0)
	{
		if (strchr(arg[0], '/') != NULL)
		{
			/* if (execvp(arg[0], arg) == -1) */
			if (execve(arg[0], arg, environ) == -1)
			{
				perror(arg[0]);
			}
		}
		else
		{
			/*exit(EXIT_FAILURE);*/
			path_env = getenv("PATH");
			if (path_env != NULL)
			{
				path_copy = strdup(path_env);
				dir = strtok(path_copy, ":");

				while (dir != NULL)
				{
					executable_path = malloc(strlen(dir) + strlen(arg[0]) + 2);
					sprintf(executable_path, "%s/%s", dir, arg[0]);
					if (access(executable_path, X_OK) == 0) {
						if (execve(executable_path, arg, environ) == -1) {
							perror(executable_path);
						}
					}
					free(executable_path);
					dir = strtok(NULL, ":");
				}
				free(path_copy);
			}
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
		last_exit_status = WEXITSTATUS(child_status);
	}
	return (-1);
}
