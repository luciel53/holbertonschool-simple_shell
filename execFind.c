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

	if (!getenv("PATH"))
		cmd[0] = checkFile(cmd[0], "");
	else
		cmd[0] = checkFile(cmd[0], getenv("PATH"));
	if (!cmd[0])
	{
		return (127);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		return(-1);
	}
	if (child_pid == 0)
	{
		execve(cmd[0], cmd, env);
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
char *checkFile(char *File, char *PATH)
{
	struct stat st;
   	char *res;
	int i = 0;
	char *path;
	int imax = strlen(PATH); 

    	if (stat(File, &st) == 0)
    	{
       		return (File);
    	}
	path = malloc(strlen(PATH) + 1);
	strcpy(path,PATH);
	for (i = 0; i < imax; i++)
	{
		if (path[i] == ':')
			path[i] = '\0';
	}
	res = calloc(200,1);
	for (i = 0; i < imax && path[i]; i += strlen(path + i) + 1)
	{
		strcpy(res, path + i);
		strcat(res, "/");
    		strcat(res, File);
		if (stat(res, &st) == 0)
    		{
			free (File);
			free (path);
        		return(res);
    		}
	}
	free(path);
    	free (File);
	free (res);
    	return (NULL);
}

