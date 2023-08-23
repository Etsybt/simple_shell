#include "shell.h"


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

size_t my_strlen(const char *str)
{
	size_t len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}


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
