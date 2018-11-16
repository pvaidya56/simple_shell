#include "shell.h"
/**
 *main - entry
 *
 */
int main(int argc, char **argv, **env)
{
	if (argc == 1 || argv[1] == NULL)
		_loop(env);
	return(0);
}
