#include <stdio.h>
#include <unistd.h>

/**
 * main - AV
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	int i;
	for(i = 1; av[i] != '\0'; i++)
	{
		printf("%s\n", av[i]);
	}
	return (0);
}
