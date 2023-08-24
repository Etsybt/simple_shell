#include "shell.h"
/**
  * int_to_str - convert from int to str
  * @num: number
  * @str: string
  * Return: void
  */
void int_to_str(int num, char *str)
{
	int i = 0;
	int len;
	int j;
	char temp;

	while (num > 0)
	{
		str[i++] = '0' + (num % 10);
		num /= 10;
	}
	str[i] = '\0';

	len = my_strlen(str);

	for (j = 0; j < len / 2; j++)
	{
		temp = str[j];
		str[j] = str[len - j - 1];
		str[len - j - 1] = temp;
	}
}
