#include "shell.h"
/**
  * my_getline - displays the input
  * Return: void
  */
char *my_getline(void)
{
	int size = 1024, line = 0, i;
	char *input = malloc(sizeof(char) * size), *new_input;

	if (!input)
	{
		perror("couldn't allocate");
		exit(EXIT_FAILURE);
	} while (1)
	{
		i = my_getchar();

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
			new_input = my_own_realloc(input, size * sizeof(char),
					size * 2 * sizeof(char));

			if (!new_input)
			{
				perror("error");
				free(input);
				exit(EXIT_FAILURE);
			}
			input = new_input;
		}
	}
	/*free(input);*/
	return (NULL);
}
