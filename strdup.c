#include "shell.h"

/**
  * my_memcpy - Copies 'n' bytes from source memory to destination memory.
  * @dest: destination memory
  * @src: source memory
  * @n: num of bytes to copy
  * Return: dest
  * @
  */
void *my_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *d = (unsigned char *)dest;
	const unsigned char *s = (const unsigned char *)src;

	while (n--)
	{
		*d++ = *s++;
	}
	return (dest);
}

/**
  * my_strlen - Computes the length of a null-terminated string.
  * @str: str to be measured
  * Return: len
  */

size_t my_strlen(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
  * my_strdup - Duplicates a null-terminated string
  * @str: string
  * Return: void
  */
char *my_strdup(const char *str)
{
	size_t len = strlen(str) + 1;
	char *new_str = (char *)malloc(len);

	if (new_str != NULL)
	{
		memcpy(new_str, str, len);
	}
	return (new_str);
}
