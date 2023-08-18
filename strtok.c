#include "shell.h"

/**
  * _strtok - splits a string
  * @input: the str to be splitted
  * Return: strings from the input
  */

char **_strtok(char *input)
{
	char *token;
	int size = 64, n = 0;
	char **str = malloc(size * sizeof(char *));

	if (!str)
	{
		fprintf(stderr, "ERROR: could not allocate\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, WHITESPACE_DELIM);
	while (str != NULL)
	{
		if (token[0] == '#')
		{
			break;
		}
		str[n] = token;
		n++;

		if (n >= size)
		{
			size += size;
			str = realloc(str, size * sizeof(char *));

			if (!str)
			{
				fprintf(stderr, "ERROR: could not reallocate\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, WHITESPACE_DELIM);
	}

	str[n] = NULL;
	return (str);
}
