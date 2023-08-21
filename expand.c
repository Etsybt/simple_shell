#include "shell.h"

int expand_variables(char **arg)
{
	int i = 0;
	char *variable_name;
	char *variable_value;

	for (; arg[i] != NULL; i++)
	{
		if (arg[i][0] == '$')
		{
			variable_name = &arg[i][1];
			variable_value = getenv(variable_name);

			if (variable_value != NULL)
			{
				free(arg[i]);
				arg[i] = strdup(variable_value);
			}
		}
	}
	return (0);
}

