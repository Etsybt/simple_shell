#include "shell.h"

/**
  * standard_stream - reads input
  * Return: input
  */

char *standard_stream(void)
{
	int chars, n = 0, size = 1024;
	char *input = malloc(sizeof(char) * size);

	if (input == NULL)
	{
		fprintf(stderr, "allocation error");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		chars = getchar();

		if (chars == EOF)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		else if (chars == '\n')
		{
			input[n] = '\0';
			return (input);
		}
		else
		{
			input[n] = chars;
		}
		n++;

		if (n >= size)
		{
			size += size;
			input = realloc(input, size);

			if (input == NULL)
			{
				fprintf(stderr, "reallocation error");
				exit(EXIT_FAILURE);
			}
		}
	}
}
