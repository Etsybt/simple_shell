#include "shell.h"
/**
 * my_own_realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 * Return: pointer to da ol'block nameen
 */
void *my_own_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *a = NULL;
	size_t copy_size, i;

	if (!ptr)
	{
		return (malloc(new_size));
	}

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	a = malloc(new_size);

	if (!a)
	{
		return (NULL);
	}

	copy_size = old_size < new_size ? old_size : new_size;

	for (i = 0; i < copy_size; i++)
	{
		a[i] = ((char *)ptr)[i];
	}


	free(ptr);
	return (a);
}
