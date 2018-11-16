#include "shell.h"
/**
 *_loop - entry point
 *
 */
void _loop(char **env)
{
	char *line = NULL;
	char **args = NULL;
	char **directory = NULL;
	char *s = NULL;

	do {
		prompt();
		line = _getline();
		{
			if (line[0] == '\n')
			{
				free(line);
				continue;
			}
		args = split_line(line);
		directory = dir_only(env);
		s = check_path(directory, args[0]);
		built_in_check(s, args);
		if (s == NULL)
			perror(s);
	} while(1);
}
