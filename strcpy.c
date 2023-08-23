#include "shell.h"

/**
 * my_strcpy - copies the string pointed to by src
 * @dest: Destination value
 * @src: Source value
 * Return: dest
 */
char *my_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i++] = '\0';
	return (dest);
}


