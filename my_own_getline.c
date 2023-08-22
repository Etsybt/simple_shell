#include "shell.h"
/**
  * my_getline - displays the input
  * Return: void
  */
char *my_getline(void)
{
	int size = 1024;
	int line = 0, i;
	char *input = malloc(sizeof(char) * size);


	if (!input)
	{
		fprintf(stderr, "couldn't allocate");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		i = getchar();

		if (i == EOF || i == '\n')
		{
			input[line] = '\0';
			return (input);
		}
		else
		{
			input[line] = i;
		}
		line++;

		if (line >= size)
		{
			size += size;
			input = realloc(input, size);

			if (!input)
			{
				fprintf(stderr, "error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
