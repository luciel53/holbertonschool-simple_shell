#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	char *blabla;
	size_t v = 1000;

	blabla = malloc(sizeof(char) * 1000);
	while (1)
	{
		printf("$ ");
		getline(&blabla, &v, stdin);

		printf("\n ce que j'imprime: %s\n", blabla);

	}
return (0);

}
