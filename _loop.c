#include "shell.h"
/**
 *_loop - Infinite Loop
 *Description: infinite loop waiting for the command
 *@env: loop with no command, or if needed, command is env
 */
void _loop(char **env)
{
	char *line;
	char **args;
	char **directory;
	char *combine;

	while (1)
	{
		prompt();
		line = _getline();
		if (line == NULL)
		{
			free(line);
			continue;
		}
		args = split_line(line);
		directory = dir_only(env);
		if (access(args[0], F_OK) == 0 && access(args[0], X_OK) == 0)
			combine = args[0];
		else
			combine = check_path(directory, args[0]);
		built_in_check(combine, args);
		if (combine == NULL)
			perror(combine);
	}
}
