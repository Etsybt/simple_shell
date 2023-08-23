#include "shell.h"
/**
  *  my_getchar - Custom implementation of getchar function.
  * Return: void
  */
int my_getchar(void)
{
	char c;

	if (read(STDIN_FILENO, &c, 1) == 1)
	{
		return ((unsigned char)c);
	}
	else
	{
		return (EOF);
	}
}
