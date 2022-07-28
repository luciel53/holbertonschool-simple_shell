#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t p_pid;

	p_pid = getppid();
	printf("%u\n", p_pid);
	return (0);
}