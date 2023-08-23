#include "shell.h"

/**
  * my_strncpy - Copies at most 'n' characters
  * from the source string to the destination string.
  * @dest: destination buffer.
  * @src: source string.
  * @n: Maximum number of characters to copy.
  * Return: void
  */

char *my_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}
