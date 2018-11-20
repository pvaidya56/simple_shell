#include "shell.h"
/**
 * get_line - Takes user input and tests 
 *
 * Description: get line from command input and test for EOF
 * Return: buffer
 */
char *get_line(void)
{
	char *buf = NULL;
	size_t bufsize = 0;
	int test;

	test = getline(&buf, &bufsize, stdin);
	if (test == EOF)
	{
		write(1, "\n", 1);
		_exit(1);
	}
	return (buf);
}
/**
 * split_line - Splits command line arguments
 * @line: command input
 * Description: split the command line into tokens or parsing the line
 * Return: tokens
 */
char **split_line(char *line)
{
	char *dup_line;
	char *token;
	char *t;
	char **tok;
	int i = 1;

	dup_line = _strdup(line);
	token = strtok(line, TOK_DELIM);
	while (token != '\0')
	{
		token = strtok(NULL, TOK_DELIM);
		i++;
	}
	free(line);
	tok = malloc(sizeof(char *) * i + 1);
	t = strtok(dup_line, TOK_DELIM);
	i = 0;
	while (t != '\0')
	{
		tok[i] = t;
		t = strtok(NULL, TOK_DELIM);
		i++;
	}
	tok[i] = '\0';
	return (tok);
}
