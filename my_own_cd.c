#include "shell.h"

/**
  * my_own_cd - custoù cd
  * @arg: arg
  * Return: 1 on success
  */

int my_own_cd(char **arg)
{
	if (arg[1] == NULL)
	{
		fprintf(stderr, "expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(arg[1]) != 0)
		{
			perror("error in my_own_cd.c\n");
		}
	}
	return (-1);
}
