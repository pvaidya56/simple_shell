#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main (void)
{
	char *substring;
	char str[] = "Hello World ok";
	int i = 0;
	char *array[3];

 	substring = strtok(str, " ");
	while (substring != NULL)
	{
		array[i++] = substring;
		substring = strtok (NULL, " ");
	}
	for (i = 0; i < 3; i++)
		printf("%s\n", array[i]);
	return (0);
}
