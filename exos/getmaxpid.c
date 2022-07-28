#include <stdio.h>
#include <unistd.h>

int main(){
	FILE *in = fopen("/proc/sys/kernel/pid_max","r");
	char c;

	while((c = fgetc(in)) != EOF)
		putchar(c);
	fclose(in);
	return 0;
}