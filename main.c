#include "shell.h"
/**
  * main - main func calls either interactive or non_interactive shell
  * Return: 0
  */

int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		shell_repl();
	}
	else
	{
		batch_mode();
	}
	return (0);
}
