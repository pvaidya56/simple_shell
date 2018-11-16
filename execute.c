#include "shell.h"
/**
 *
 *
 *
 */

int execute(char *s, char **input)
{
	pid_t child, wait_p;
	int status;

	child = fork();
	if (child == 0)
	{
		status = execve(s, input, NULL);
		if (status == -1);
		{
			write(STDERR_FILENO, "built: execve error\n", 6);
			return(-1);
		}
	}
	else if (child < 0)
	{
		write(STDERR_FILENO, "built: pid error\n", 6);
		return(-2);
	}
	else
	{
		wait_p = wait(&status);
	}

	return (status);
}
