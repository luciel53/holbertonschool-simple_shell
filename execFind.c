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
	char temp[200];

	strcpy(temp,cmd[0]);
	cmd[0] = checkFile(cmd[0], getenv("PATH"));
	if (!cmd[0])
	{
		dprintf(STDERR_FILENO, "%s: 1: %s: not found\n", getenv("_"), temp);
		return (127);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		return(-1);
	}
	if (child_pid == 0)
	{
		exit (execve(cmd[0], cmd, env));
	}
	wait(&status);
	return (status);
}

/**
 **checkfile - A function that finds a file
 * @File: the file we want to find
 * @PATH: current path
 * Return: if the file is found in the current directory or in bin, return the
 * 	result, else return NULL
 */
char *checkFile(char *File, char* PATH)
{
	struct stat st;
   	char *res;

	res = calloc(strlen(File) + strlen(PATH) + 1, 1);
    	strncat(res, PATH, strlen(PATH));
    	strncat(res, File, strlen(File));
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
