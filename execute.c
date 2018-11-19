#include "shell.h"
/**
 *
 *
 *
 */

int execute(char *combine, char **input)
{
	pid_t pid;
	int status = 0;

	pid = fork();
	if (pid == 0)
	{
		status = execve(combine, input, NULL);
		exit(status);
/*	if ((execve(input[0], input, NULL)) == -1)
		{
			perror("Execution error: ");
			return(-1);
			} */
	}
	else if (pid < 0)
	{
		perror("No process: ");
		return(-1);
	}
	else /* parrent*/
	{
		wait(NULL);
	}
	return (status);
}
