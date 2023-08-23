#include "shell.h"
/**
  * main - main func calls either interactive or non_interactive shell
  * Return: 0
  */

int main(void)
{
	ShellInfo shell_info;

	shell_info.last_exit_status = 0;

	setenv("PATH", "/bin:/usr/bin", 1);

	if (isatty(STDIN_FILENO) == 1)
	{
		shell_repl(&shell_info);
	}
	else
	{
		batch_mode(&shell_info);
	}
	return (0);
}
