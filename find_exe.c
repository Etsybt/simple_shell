#include "shell.h"

/**
  * find_executable - finds executable
  * @file: file
  * Return: void
  */
char *find_executable(const char *file)
{
	char *path, *dir, *executable_path;
	struct stat statbuf;
	int dir_len, file_len;
	char *full_path;

	path = getenv("PATH");
	dir = strtok(path, ":");
	executable_path = NULL;

	if (file[0] == '/')
	{
		if (stat(file, &statbuf) == 0 && S_ISREG(statbuf.st_mode)
				&& (statbuf.st_mode & S_IXUSR))
		{
			return (strdup(file));
		} return (NULL);
	} while (dir != NULL)
	{
		dir_len = my_strlen(dir);
		file_len = my_strlen(file);
		full_path = malloc(dir_len + file_len + 2);

		if (!full_path)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		my_strcpy(full_path, dir);
		full_path[dir_len] = '/';
		my_strcpy(full_path + dir_len + 1, file);

		if (stat(full_path, &statbuf) == 0 && S_ISREG(statbuf.st_mode)
				&& (statbuf.st_mode & S_IXUSR))
		{
			executable_path = my_strdup(full_path);
			free(full_path);
			break;
		} free(full_path);
		dir = strtok(NULL, ":");
	} return ((executable_path));
}
