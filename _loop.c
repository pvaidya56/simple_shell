#include "shell.h"
/**
 *_loop - entry point
 *
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
		if (line == "\0")
		{
			free(line);
			continue;
		}
		args = split_line(line);

/**		if (access(args[0], F_OK) != 0 && access(args[0], X_OK) != 0)
			combine = get_PATH_token(args[0]);
		printf("command is %s\n", args[0]);
		printf("combine is %s\n", combine);
		if (combine)
			args[0] = combine;
		printf("command after change is %s\n", args[0]);
		launch = execute(args); */
		directory = dir_only(env);
		combine = check_path(directory, args[0]);
		built_in_check(combine, args);
		if (combine == NULL)
			perror(combine);
	}
	free(line);
	free(args);
	free(directory);
	free(combine);
}
