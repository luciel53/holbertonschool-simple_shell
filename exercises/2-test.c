#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	char str[] = " Coucou-ptite-poule";

	char * separators = "-";

	char * token = strtok ( str, separators );

	while ( token != NULL )
	{
		printf ( "%s\n", token );
		token = strtok ( NULL, separators );
	}

	return (0);
}
