#include "shell.h"

/**
  * main - calls either interactive or non_interactive shell
  * Return: 0
  */

int main(void)
{
	isatty(STDIN_FILENO) ? interactive() : no_interactive();
	return (0);
}
