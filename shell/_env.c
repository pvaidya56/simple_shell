#include "shell.h"
/**
 *env - entry point
 *@env: enviroment variable
 *Description: function to print out enviroment variable
 */
void env(char **env)
{
	int word;

	for (word = 0; env[word] != NULL; word++)
	{
		write(1, env[word], _strlen(env[word]));
		write(1, "\n", 1);
	}
}