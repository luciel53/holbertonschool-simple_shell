#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include"main.h"

void strcut(char *str, char **res, int *p)
{
	char *saveptr;
	char *pch;

	pch = strtok_r (str," \n", &saveptr);
	while (pch != NULL)
	{
		res[*p] = malloc(strlen(pch) + 1);
		strcpy(res[*p], pch);
		(*p)++;
		pch = strtok_r (NULL, " \n",&saveptr);
	}
}
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
 * main - executer la command entré par l'utilisateur
 * Return: 1
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
		/*for (i = 0; split[i]; i ++)
			printf("%s\n", split[i]);*/
		if(!split[0])
		{
			line[0] = 0;
			continue;
		}
		if (execute(split,env) == - 1)
			printf("Error: command not found\n");
		for (i = 0; split[i]; i++)
			free (split[i]);
		memset(split, '\0', 200);
		line[0] = 0;
	}
	free(split);
	free(line);
	return (0);
}