#include "shell.h"

int main (void)
{
	int status;
	pid_t child;
	char *buffer;
	size_t buffsize = 0;
	char *token[1024];
	size_t letters;

	while ()
	{
		child = fork();
		if (child == -1)
			return (-1);
		if (child == 0)
		{
			write(STDIN
		}


		if (child > 0)
			wait(&status);
	}
	return (0);
}
