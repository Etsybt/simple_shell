#include "shell.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putstr - prints a string
 * @str: string
 */

void _putstr(const char *str)
{
	const char *ptr = str;

	for (; *ptr != '\0'; ptr++)
	{
		_putchar(*ptr);
	}
}

