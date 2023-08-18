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
		fprintf(stderr, "changing dir\n");
		return (-1);
	}
	else
	{
		if (chdir(arg[1]) == -1)
		{
			perror("error in my_own_cd.c");
		}
	}
	return (-1);
}
