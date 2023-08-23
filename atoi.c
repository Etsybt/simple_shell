#include "shell.h"

int my_atoi(const char *str)
{
	int result = 0;
	bool is_negative = false;

	if (*str == '-')
	{
		is_negative = true;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (is_negative ? -result : result);
}
