#include "shell.h"
/**
 *_getchar - entry point
 *Description: create my own version of getchar, get 1 character
 *Return: character
 */
int _getchar(void)
{
	char letter[1];
	int i = read(0, letter, 1);

	if (i < 1)
		exit(1);
	return (letter[0]);
}