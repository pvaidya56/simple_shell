#ifndef _SHELL_H
#define _SHELL_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stddef.h>

#define TOK_DELIM " \n\a\t"
void prompt(void);
char *read_line(void);
char **split_line(char *line);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strdup(char *str);

#endif
