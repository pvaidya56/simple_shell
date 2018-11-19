#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *buffer;
	size_t bufsize = 32;
	char  characters;

	buffer = (char *)malloc(bufsize * sizeof(char));
	if( buffer == NULL)
	{
		exit(1);
	}

	printf("$ ");
	characters  = getline(&buffer,&bufsize,stdin);
	printf("%s\n", buffer);
	(void) characters;
	return(0);
}