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
 * @cmd: command
 * @env: double pointer to the environnement variable
 * Return: 0 or non zero if it fails.
 */

int execute(char **cmd, char **env)
{
	pid_t child_pid;
	int status;
	char *thisEnv;
	char **en;

	if (!strcmp(cmd[0], "env"))
	{
		for (en = env; *en != 0; en++)
		{
			thisEnv = *en;
			printf("%s\n", thisEnv);
		}
		return (0);
	}
	cmd[0] = checkFile(cmd[0], getenv("PATH"));
	if (!cmd[0])
	{
		return (127);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		return (-1);
	}
	if (child_pid == 0)
	{
		execve(cmd[0], cmd, env);
	}
	wait(&status);
	if (status)
		return (2);
	return (0);
}

/**
 * *checkFile - A function that finds a file
 * @File: the file we want to find
 * @PATH: current path
 * Return: if the file is found in the current directory or in bin, return the
 *	result, else return NULL
 */
char *checkFile(char *File, char *PATH)
{
	struct stat st;
	char *res, *path;
	unsigned int i = 0, imax, ispath = 0;

		if (stat(File, &st) == 0)
		{
		for (i = 0; i < strlen(File); i++)
			ispath += (File[i] == '/');
		if (ispath)
			return (File);
		}
	if (!PATH)
	{
		free(File);
		return (NULL);
	}
	imax = strlen(PATH);
	path = malloc(strlen(PATH) + 1);
	strcpy(path, PATH);
	for (i = 0; i < imax; i++)
		if (path[i] == ':')
			path[i] = '\0';
	res = calloc(200, 1);
	for (i = 0; i < imax && path[i]; i += strlen(path + i) + 1)
	{
		strcpy(res, path + i);
		strcat(res, "/");
			strcat(res, File);
		if (stat(res, &st) == 0)
			{
			free(File);
			free(path);
				return (res);
			}
	}
	free(path);
		free(File);
	free(res);
		return (NULL);
}

