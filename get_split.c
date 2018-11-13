#include "shell.h"
/**
 *read_line - entry point
 *Description: read entered command line
 *Return: line
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	int checkline;

	checkline = getline(&line, &bufsize, stdin);
	if (checkline == EOF)
	{
		write(1, "\n", 1);
		exit(1);
	}
	return (line);
}

/**
 * split_line - entry point
 * @line: command input
 * Description: split the command line into tokens or parsing the line
 * Return: tokens
 */
char **split_line(char *line)
{
	char *dup_line;
	char *token;
	char *toks;
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
	toks = strtok(dup_line, TOK_DELIM);
	i = 0;
	while (toks != '\0')
	{
		tok[i] = toks;
		toks = strtok(NULL, TOK_DELIM);
		i++;
	}
	tok[i] = '\0';
	return (tok);
}
