#include "shell.h"
static void allocate_memory(char ***str, int *size, int n);
static void add_token(char ***str, int *n, const char *start, const char *end);
static void reallocate_memory(char ***str, int *size);

char **my_strtok(char *input)
{
	int size = 64, n = 0;
	char **str = malloc(size * sizeof(char *));
	char *start = input, *end = input;
	
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
			add_token(&str, &n, start, end);
			if (n >= size)
			{
				reallocate_memory(&str, &size);
				if (!str)
				{
					fprintf(stderr, "ERROR: could not reallocate\n");
					exit(EXIT_FAILURE);
				}
			}
		}
	}
	str[n] = NULL;
	return str;
}

static void allocate_memory(char ***str, int *size, int n)
{
	if (n >= *size)
	{
		*size += *size;
		*str = realloc(*str, *size * sizeof(char *));
	}
}

static void add_token(char ***str, int *n, const char *start, const char *end)
{
	size_t token_len = end - start;
	allocate_memory(str, n, *n);
	(*str)[*n] = malloc((token_len + 1) * sizeof(char));
	strncpy((*str)[*n], start, token_len);
	(*str)[*n][token_len] = '\0';
	(*n)++;
}

static void reallocate_memory(char ***str, int *size)
{
	*size += *size;
	*str = realloc(*str, *size * sizeof(char *));
}

