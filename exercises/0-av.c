#include <stdio.h>

int main(int ac, char **av)
{
	int i;

	while (av[i] != NULL)
	{
		i++;
		printf("%s\n", av[i]);
	}
return (0);
}
