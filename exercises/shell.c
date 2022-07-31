#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main -
 *
 * @return int
 */
int main()
{
	char *blabla;
	int status;
	pid_t child_pid;
	size_t v = 1000;

	char *arr[2];


	blabla = malloc(sizeof(char) * 1000);
	while (1)
	{
		printf("cisfun$ ");
		getline(&blabla, &v, stdin);
		blabla[strlen(blabla) -1] = '\0';
		arr[0] = blabla;
		arr[1] = NULL;

		child_pid = fork();

			if (child_pid == -1)
			{
				perror("Error");
				return (1);
			}
			if (child_pid == 0)
			{
				execve(arr[0], arr, NULL);
			}
	wait(&status);
	}

return (0);
}
