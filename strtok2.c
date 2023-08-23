#include "shell.h"
/**
  * allocate_initial_memory - allocates memo
  * @size: memo size
  * Return: void
  */
char **allocate_initial_memory(size_t size)
{
	char **str;

	str = malloc(size * sizeof(char *));

	if (!str)
	{
		perror("ERROR: malloc");
		exit(EXIT_FAILURE);
	}
	return (str);
}

/**
  * realloc_memory - reallocate memo
  * @str: string
  * @size: size
  * Return: void
  */
char **realloc_memory(char **str, size_t *size)
{
	char **new_str;

	*size += *size;

	new_str = realloc(str, *size * sizeof(char *));

	if (!new_str)
	{
		perror("ERROR: realloc");
		exit(EXIT_FAILURE);
	}
	return (new_str);
}

/**
  * add_token - adds token
  * @str: string
  * @n: int
  * @size: size
  * @start: the start
  * @end: the end
  * Return: void
  */

void add_token(char **str, size_t *n, size_t *size,
		const char *start, const char *end)
{
	size_t token_len = end - start;

	str[*n] = malloc((token_len + 1) * sizeof(char));

	if (!str[*n])
	{
		perror("ERROR: malloc");
		exit(EXIT_FAILURE);
	}
	my_strncpy(str[*n], start, token_len);
	str[*n][token_len] = '\0';
	(*n)++;

	if (*n >= *size)
	{
		str = realloc_memory(str, size);
	}
}
/**
  * my_strtok2 - splits a string
  * @input: input
  * Return: void
  */

char **my_strtok2(char *input)
{
	size_t n = 0;
	size_t size = 64;
	char **str = allocate_initial_memory(size);
	char *start = input, *end = input, **new_str;

	while (*end != '\0')
	{
		while (*end && my_strchr(WHITESPACE_DELIM, *end))
			end++;
		start = end;

		while (*end && !my_strchr(WHITESPACE_DELIM, *end))
			end++;

		if (start != end)
		{
			add_token(str, &n, &size, start, end);
		}
	}
	str[n] = NULL;

	if (n < size)
	{
		new_str = realloc(str, (n + 1) * sizeof(char *));

		if (new_str)
		{
			str = new_str;
		}
	}
	return (str);
}
