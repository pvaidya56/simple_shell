#include "shell.h"
/**
 *main - entry
 *@argc: argument count
 *@argv: argument
 *@env: implementation env
 *Return: 0 for success
 */
int main(int argc, char **argv, char **env)
{
	if (argc == 1 || argv[1] == NULL)
		_loop(env);
	return (0);
}
