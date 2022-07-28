#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av)
{
	int i;

	for (i = 0; av[i]; i++)
		printf("%s", av[i]);
	return (0);
}