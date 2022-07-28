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
 * execute - A function that executes the program of the command given
 * @argv: command
 * @env: double pointer to the environnement variable
 * Return: Always 0.
 */

int execute (char **cmd, char **env)
{
	pid_t child_pid;
	int status;

	cmd[0] = checkFile(cmd[0]);
	if (!cmd[0])
		return (-1);
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (child_pid == 0)
	{
		execve(cmd[0], cmd, env);
	}
	wait(&status);
	return (0);
}

/**
 * *checkfile - A function that finds a file
 * @File: the file we want to find
 * Return: if the file is found in the current directory or in bin, return the
 * 			result, else return NULL
 */
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
