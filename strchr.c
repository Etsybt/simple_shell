#include "shell.h"

/**
  * my_strchr - Custom implementation of strchr function.
  * Searches for the first occurrence of a character in a string.
  * @str: string
  * @c: int
  * Return: void
  */
char *my_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
