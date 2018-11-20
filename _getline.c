#include "shell.h"
/**
 *_getline - Takes input from user
 *Description: Getline function
 *Return: User Input
 */
char *_getline(void)
{
	int inputsize = 1024;
	int i = 0;
	char *input = malloc(sizeof(char) * inputsize);
	int a;

	if (input == NULL) /*allocate memory for input, if not, exit */
		exit(1);
	while (1) /*infinite loop, use getchar to read character*/
	{
		a = _getchar();
		if (a == EOF || a == '\n')
		{
			input[i] = '\0';
			return (input);
		}
		else
			input[i] = a;
		i++;
		if (i >= inputsize)
		{
			inputsize += 1024;
			input = realloc(input, inputsize);
			if (input == NULL)
				exit(1);
		}
	}
}
