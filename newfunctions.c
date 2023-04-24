#include "main.h"

char **tokenize(char *comand, int read)
{
char *copycom = NULL;
char *token;
char **argv;
int count = 0, i = 0, j = 0;

copycom = malloc(sizeof(char) * read);
		if (copycom == NULL)
		{
			free(copycom);
			return(NULL);
		}
		strcpy(copycom, comand);
		token = strtok (comand, " \n");
		while (token != NULL)
		{
			count++;
			token = strtok(NULL," \n");
		}
		count++;
		argv = malloc(sizeof(char *) * count);
		if (argv == NULL)
		{
			free(argv);
			return(NULL);
		}
		token = strtok(copycom, " \n");

		for(i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token) + 1);
			if (argv[i] == NULL)
			{
				for(j = 0; j < i; j++)
					free(argv[j]);
				free(argv);
				return(NULL);
			}
			strcpy(argv[i], token);
			token = strtok(NULL, " \n");
		}
		argv[i] = NULL;
        free(copycom);
        return(argv);
}

int free_token(char **comand)
{
    int x;

    if (!comand)
        return(0);

        for (x = 0; comand[x] != NULL; x++)
            free(comand[x]);
        
        free(comand);
        comand = NULL;
        
        return(0);
}
void excecute(char **tokenargv)
{
    pid_t newpid;
    char **argv;
    int status = 0;

    argv = tokenargv;
    

    newpid = fork();
		if (newpid == -1)
		{
			exit(EXIT_FAILURE);
		}
		else if (newpid == 0)
		{
			if(execve(argv[0], argv, NULL) == -1)
			{
				printf("Comand not found \n");
				exit(1);
			}
		}
		else
		{
			wait(&status);
        }
	}


