#include "shell.h"
/**
 *str_concat - Entry point
 *@s1 : string 1
 *@s2 : string 2
 *Return: pointer contain the string 1 and 2
 */
char *str_concate(char *s1, char *s2)

{
	int index1, index2, size1, size2;
	char *s;
	int combine;

	size1 = _strlen(s1);
	size2 = _strlen(s2);
	combine = size1 + size2 + 1;
	s = malloc(combine * sizeof(char));
	if (s == NULL)
		return (NULL);
	for (index1 = 0, index2 = 0; index1 < combine; index1++)
	{
		if (index1 < size1)
			s[index1] = s1[index1];
		else if (index1 == size1)
			s[index1] = '/';
		else
			s[index1] = s2[index2++];
	}
	return (s);
}

/**
 *
 *
 */
char *get_PATH_token(char *command)
{
	char *getPATH = NULL;
	char *token = NULL;
	char *combine = NULL;

	getPATH = getenv("PATH");
	token = strtok(getPATH, ":");
	while(token != '\0')
	{
		combine = str_concate(token, command);
		if (access(combine, F_OK) == 0 && access(combine, X_OK) == 0)
		{
			printf("its all gioof");
			return(combine);
		}
		token = strtok(NULL, ":");
	}
	return(combine);
}
