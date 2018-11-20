#include "shell.h"
/**
 *execute - Executes Functions
 *Description: execute after fork
 *@combine: combine directory and input
 *@input: input command
 *Return: status of the process
 */

int execute(char *combine, char **input)
{
	pid_t pid;
	int status = 0;

	pid = fork();
	if (pid == 0)
	{
		status = execve(combine, input, NULL);
		if (status == -1)
		{
			write(STDERR_FILENO, "Error: execve error\n", 6);
			exit(status);
		}

	}
	else if (pid < 0)
	{
		perror("No process: ");
		return (-1);
	}
	else /* parent*/
	{
		wait(NULL);
	}
	return (status);
}
