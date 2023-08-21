#include "shell.h"

char **my_strtok(char *input)
{
	int size = 64, n = 0;
	char **str = malloc(size * sizeof(char *));
	char *start = input;
	char *end = input;

	if (!str)
	{
		fprintf(stderr, "ERROR: could not allocate\n");
		exit(EXIT_FAILURE);
	}

	while (*end != '\0')
	{
		while (*end && strchr(WHITESPACE_DELIM, *end))
			end++;

		start = end;

		while (*end && !strchr(WHITESPACE_DELIM, *end))
			end++;

		if (start != end)
		{
			size_t token_len = end - start;
			str[n] = malloc((token_len + 1) * sizeof(char));
			strncpy(str[n], start, token_len);
			str[n][token_len] = '\0';
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
		}
	}
	str[n] = NULL;
	return (str);
}
