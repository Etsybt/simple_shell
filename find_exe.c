#include "shell.h"

char *find_executable(const char *file)
{
	char *path;
	char *dir;
	char *executable_path;
	struct stat statbuf;

	path = getenv("PATH");
	dir = strtok(path, ":");
	executable_path = NULL;


	if (file[0] == '/')
	{
		if (stat(file, &statbuf) == 0 && S_ISREG(statbuf.st_mode) && (statbuf.st_mode & S_IXUSR))
		{
			return strdup(file);
		}
		return NULL;
	}

	while (dir != NULL)
	{
		char full_path[MAX_PATH_LENGTH];

		snprintf(full_path, sizeof(full_path), "%s/%s", dir, file);

		if (stat(full_path, &statbuf) == 0 && S_ISREG(statbuf.st_mode) && (statbuf.st_mode & S_IXUSR))
		{
			executable_path = my_strdup(full_path);
			break;
		}
		dir = strtok(NULL, ":");
	}
	return (executable_path);
}
