#include "shell.h"

/**
  * _getline - reads an entire line from stream
  * Return: input
  */

char *_getline(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&input, &len, stdin);

	if (read == -1)
	{
		if (feof(stdin))
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(input);
			perror("could not read input");
			exit(EXIT_FAILURE);
		}
	}
	return (input);
}
