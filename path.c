#include "shell.h"
/**
 *path_concate - Entry point
 *Description: combine directory from PATH to the command
 *@directory : directory
 *@argument: input command
 *Return: Pointer that  contains the string 1 and 2
 */
char *path_concate(char *directory, char *argument)

{
	int index1;
	int index2;
	int size1, size2;
	char *s;

	if (directory == 0)
		directory = "";
	if (argument == 0)
		argument = "";
	for (size1 = 0; directory[size1] != '\0'; size1++)
	{
		;
	}
	for (size2 = 0; argument[size2] != '\0'; size2++)
	{
		;
	}
	size2++;
	s = malloc(size1 * sizeof(*directory) + size2 * sizeof(*argument));
	if (s == 0)
	{
		return (NULL);
	}
	for (index1 = 0, index2 = 0; index1 < size1 + size2; index1++)
	{
	if (index1 < size1)
		s[index1] = directory[index1];
	else
		s[index1] = argument[index2++];
	}
	return (s);
}
/**
 * get_env - entry point
 * @env: enviroment variable
 * Description: get environment variables with no argument
 * Return: tokens
 */
char *get_env(char **env)
{
	int c, b, len;
	char *s = "PATH";
	char *start, *buf;

	c = 0;
	while (env[c])
	{
		b = 0;
		while (env[c][b] == s[b])
		{
			if (env[c][b + 1] == s[b + 1])
			{
				start = env[c];
				break;
			}
			b++;
		}
		c++;
	}
	len = _strlen(start);
	buf = malloc(sizeof(char) * len + 9);

	c = 5;
	b = 0;
	while (start[c] != '\0')
	{
	if (start[c] == ':')
	{
		buf[b] = '/';
		b++;
	}
	buf[b] = start[c];
	c++;
	b++;
	}
	buf[b] = '/';
	b++;
	buf[b] = '\0';
	return (buf);
}
/**
 * dir_only - entry point
 * @env: enviroment variable
 * Description: Splits directory for no argument
 * Return: buffer
 */
char **dir_only(char **env)
{
	char **tokens;
	char *tok;
	int i;
	char *directory;

	directory = get_env(env);
	i = 0;
	tokens = malloc(sizeof(char *) * 9);
	tok = strtok(directory, " :");
	while (tok != NULL)
	{
		tokens[i] = tok;
		i++;
		tok = strtok(NULL, " :");
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * check_path - entry point
 * @directory: directory
 * @input:input
 * Description: checks path
 * Return: full path or 0
 */
char *check_path(char **directory, char *input)
{
	struct stat st;
	char *path;


	while (*directory != '\0')
	{
		path = path_concate(*directory, input);
		if (stat(path, &st) == 0)
			return (path);
		directory++;
	}
	return (NULL);
}
