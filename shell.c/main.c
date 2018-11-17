#include "shell.h"
/**
 *  main - Main shell function
 *
 *
 *Return - Always 0.
 */

int main(void)
{
	int status;
	pid_t child;
	char *buffer;
	size_t buffsize = 0;
	char *split[1024];
	size_t letters;
	int index;

	while (1)
	{
		child = fork();
		if (child == -1)
			return (-1);
		if (child == 0)
		{
			write(STDIN_FILENO, "$ ", 2);
			letters = (getline(&buffer, &buffsize, 1));
			if (letters == -1)
				return (-1);
			if ((buffer)[letters - 1] == '\n')
			{
				(buffer)[letters - 1] = '\0';
			}
			token = strtok(buffer, " ");
			while (split[index] != NULL)
			{
				split[index] = strtok(NULL, " ");
				index++;
			}
			execve(split[0], split, NULL);
			perror("Execution Error");
			return (-1);
		}
		if (child > 0)
			wait(&status);
	}
	return (0);
}
