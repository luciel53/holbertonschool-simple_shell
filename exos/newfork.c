#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
	pid_t child_pid;
	int status;
	int i = 0;
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};
		for (i = 0 ; i < 4 ; i++)
		{
			child_pid = fork();

			if (child_pid == -1)
			{
				perror("Error");
				return (1);
			}
			if (child_pid == 0)
			{
				execve(argv[0], argv, NULL);
				printf("\n\n\nok");
			}
	wait(&status);
	}
	printf("it works.....or not");
		return (0);

}
