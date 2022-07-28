#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include"main.h"

/**
 * strcut - A function that cuts the string at spaces and line returns and
 * 			put its result in an array
 * @str: pointer to a string that we want to cut
 * @res: array of string to edit
 * @p: position in array from which we have to add
 * Return: void
 */

void strcut(char *str, char **res, int *p)
{
	char *saveptr;
	char *pch;

	pch = strtok_r (str, " \n", &saveptr);
	while (pch != NULL)
	{
		res[*p] = malloc(strlen(pch) + 1);
		strcpy(res[*p], pch);
		(*p)++;
		pch = strtok_r (NULL, " \n" ,&saveptr);
	}
}

/**
 * prepcmd - A function that prepares the use of the command
 * @str: pointer to a string that we want to cut
 * @res: array of string to edit
 * Return: void
 */

void prepcmd(char *str, char **res)
{
	char *pch;
	char *saveptr;
	int p = 0;
	int even = 0;

	pch = strtok_r (str,"\"", &saveptr);
	while (pch != NULL)
	{
		if (even % 2 == 0)
			strcut(pch, res, &p);
		else
		{
			res[p] = malloc(strlen(pch) + 1);
			strcpy(res[p], pch);
			p++;
		}
		pch = strtok_r (NULL, "\"",&saveptr);
		even++;
	}
}


/**
 * main - A function that simukes the shell
 * @ac: argument count
 * @av: argument vector
 * @env: double pointer to the environnement variable
 * Return: 0 if it works or something else if not
 */


int main (int ac, char **av, char **env){
	/*size_t lenPth = 201;
	char buf[200];
	char *usrName;
	char *path;
	char hostname[200];*/
	char *line = NULL;
	size_t len = 0;
	int i;
	int err = 0;
	char *cmd = malloc(200);
	char **split = calloc (200, 1);

	if (ac != 1 && av[0])
		return (-1);
	/*usrName = getenv("USER");
	path = getcwd(buf, lenPth);
	gethostname(hostname, 201);*/
	while (line == NULL || strcmp(line,"exit"))
	{
		/*printf("%s@%s:%s$ ", usrName, hostname, path);*/
		fflush(stdout);
		getline(&line, &len, stdin);
		if(!line[0] || !strcmp(line,"exit\n"))
		{
			break;
		}
		prepcmd(line, split);
		strcpy(cmd,split[0]);
		/*for (i = 0; split[i]; i ++)
			printf("%s\n", split[i]);*/
		if(!split[0])
		{
			line[0] = 0;
			continue;
		}
		err = execute(split, env);
		if (err == 127)
			dprintf(STDERR_FILENO, "%s: 1: %s: not found\n", av[0], cmd);
		for (i = 0; split[i]; i++)
			free (split[i]);
		memset(split, '\0', 200);
		line[0] = 0;
	}
	free (cmd);	
	free(split);
	free(line);
	return (err);
}
