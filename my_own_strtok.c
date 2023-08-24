#include "shell.h"
/**
  * my_strtok - splits the input into strings
  * @input: string
  * Return: strings
  */
char **my_strtok(char *input)
{
	int size = 64, n = 0;
	char **str = malloc(size * sizeof(char *)),
	     *start = input, *end = input, **new_str;

	if (!str)
	{ perror("ERROR: malloc");
		exit(EXIT_FAILURE);
	} while (*end != '\0')
	{
		while (*end && my_strchr(WHITESPACE_DELIM, *end))
			end++;
		start = end;

		while (*end && !my_strchr(WHITESPACE_DELIM, *end))
			end++;
		if (start != end)
		{   size_t token_len = end - start;

			str[n] = malloc((token_len + 1) * sizeof(char));
			my_strncpy(str[n], start, token_len);
			str[n][token_len] = '\0';
			n++;

			if (n >= size)
			{      size += size;
				new_str = my_own_realloc(str, size * sizeof(char *),
						(n + 1) * sizeof(char *));

				if (!new_str)
				{       perror("ERROR: realloc");
					exit(EXIT_FAILURE);
				} str = new_str;
			}}} str[n] = NULL;
	if (n < size)
	{ new_str = realloc(str, (n + 1) * sizeof(char *));

		if (new_str)
			str = new_str;
	} return (str);
}
