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
void _loop(void);
#define TOK_DELIM " \n\a\t"
int _getchar(void);
char *_getline(void);
void prompt(void);
char **split_line(char *line);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strdup(char *str);

#endif
