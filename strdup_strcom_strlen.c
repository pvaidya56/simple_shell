#include "shell.h"
/**
 *_strcmp - Compares 2 strings
 *@s1: string 1
 *@s2: string 2
 *Description: compare 2 strings for matching
 *Return: 0 if success, -1 for fail
 */
int _strcmp(char *s1, char *s2)

{
	int index;

	for (index = 0; s1[index] != '\0' && s2[index] != '\0'; index++)
	{
		if (s1[index] != s2[index])
			return (s1[index] - s2[index]);
	}
	return (0);
}

/**
 *_strlen - Gets the length of a string
 *@s: value of s
 *Description: length of string
 *Return: length of string
 */

int _strlen(char *s)

{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}

/**
 *_strdup - Duplicates a string
 *@str : string
 *Return: pointer contain the copy of str
 */
char *_strdup(char *str)

{
	int index;
	int size;
	char *s = NULL;

	if (str == 0)
		return (NULL);
	for (size = 0; str[size] != '\0'; size++)
	{
		;
	}
	size++;
	s = malloc(size * sizeof(*s));
	if (s == 0)
	{
		return (NULL);
	}
	for (index = 0; index < size; index++)
		s[index] = str[index];
	return (s);
}
