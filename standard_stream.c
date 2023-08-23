#include "shell.h"
/**
  * standard_stream - reads input
  * Return: input
  */
char *standard_stream(void)
{
	int size = 1024, n = 0, chars;
	char *input = malloc(sizeof(char) * size);

	if (input == NULL)
	{
		perror("allocation error");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		chars = my_getchar();

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
			input = my_own_realloc(input, size * sizeof(char), size * 2 * sizeof(char));

			if (input == NULL)
			{
				perror("reallocation error");
				exit(EXIT_FAILURE);
			}
		}
	}
}
