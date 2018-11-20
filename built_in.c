#include "shell.h"

/**
 * myexit - Exits program
 * @input: input
 * Description: implementation of exit from the program
 * Return: 0 for success
 */

int myexit(char **input)
{
	(void) input;
	exit(0);
}

/**
 * print_env - Prints environment variable
 * @input: pointer to the command
 * Description: printout env
 * Return: 0 if success
 */
int print_env(char **input)
{
	int i, k;

	for (i = 0; environ[i] != NULL; i++)
	{
		k = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], k);
		write(1, "\n", 1);
	}
	(void)input;
	return (1);
}

/**
 * built_in_check - Function that checks for built-ins 
 * @s: full string line
 * @input: input
 * Description: check for if built-in and function call
 * Return: path to built-in
 */
int built_in_check(char *s, char **input)
{
	int i;
	char *arr[] = {"exit", "env", NULL};


	typedef int (*built_in)(char **);
	built_in functions[] = {&myexit, &print_env};

	i = 0;
	while (arr[i] != NULL)
	{
		if (_strcmp(arr[i], input[0]) == 0)
			return (functions[i](input));
		i++;
	}
	return (execute(s, input));
}
