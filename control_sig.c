#include "shell.h"

void control_sig(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	prompt();
}
