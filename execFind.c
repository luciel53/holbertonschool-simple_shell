#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include"main.h"
/**
 * main - execve example
 *
 * Return: Always 0.
 */

int execute (char **argv, char **env)
{
	pid_t child_pid;
	int status;

    	argv[0] = checkFile(argv[0]);
	if (!argv[0])
		return (-1);
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (child_pid == 0)
	{
		execve(argv[0], argv, env);
	}
	wait(&status);
	return (0);
}

char *checkFile(char *File)
{   
    	struct stat st;
   	char *res;
    
    	if (stat(File, &st) == 0) 
    	{
       		return (File);
    	}
	res = calloc(strlen(File) + 6, 1);
    	strncat(res, "/bin/",6);
    	strncat(res, File, strlen(File));
    	free (File);
    	if (stat(res, &st) == 0)
    	{
        	return(res);
    	}
	free (res);
    	return (NULL);
}