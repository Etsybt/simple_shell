#include "shell.h"
/**
  *  my_getchar - Custom implementation of getchar function.
  * Return: void
  */
int my_getchar(void)
{
	static char buffer[1024];
	static int position;
	static int bytesRead;

	if (position >= bytesRead)
	{
		bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer));
		if (bytesRead <= 0)
		{
			return (EOF);
		}
		position = 0;
	}
	return (buffer[position++]);
}
