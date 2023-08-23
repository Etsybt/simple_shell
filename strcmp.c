#include "shell.h"
/**
  * my_strcmp - Custom implementation of strcmp function.
  * Compares two strings lexicographically.
  * @s1: char 1
  * @s2: char 2
  * Return: void
  */
int my_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
