#include "shell.h"
/**
 *main - Main funtion
 *@argc: argument count
 *@argv: argument
 *@env: implementation env
 *Return: 0 for success
 */
int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)**argv;
	_loop(env);
	return (0);
}
