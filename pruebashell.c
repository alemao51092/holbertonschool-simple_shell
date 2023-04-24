
#include "main.h"

int main(int ac, char *av[])
{
	char *comand = NULL, *copycom = NULL;
	size_t n = 0;
	int read;
	char *token;
	int count = 0, i = 0, status, j, x;
	pid_t newpid;
	char **argv;


	while (1)
	{
		printf("Ale ~$: ");
		read = getline(&comand,&n, stdin);
		if(read == -1)
		{
		    printf("\n");
		    exit (1);
		}
		if (comand[read - 1] == '\n') 
			comand[read - 1] = '\0';
		
		copycom = malloc(sizeof(char) * read);
		if (copycom == NULL)
		{
			free(copycom);
			return (-1);
		}
		strcpy(copycom, comand);
		token = strtok (comand, " ");
		while (token != NULL)
		{
			count++;
			token = strtok(NULL," ");
		}
		count++;
		argv = malloc(sizeof(char *) * count);
		if (argv == NULL)
		{
			free(argv);
			return(-1);
		}
		token = strtok(copycom, " ");

		for(i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token) + 1);
			if (argv[i] == NULL)
			{
				for(j = 0; j < i; j++);
					free(argv[j]);
				free(argv);
				return(-1);
			}
			strcpy(argv[i], token);
			token = strtok(NULL, " ");
		}
		argv[i] = NULL;
		
		
		newpid = fork();
		if (newpid == -1)
		{
			return(-1);
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
		for(int j = 0; j < i; j++)
			free(argv[j]);
		free(argv);
		free(copycom);
	}

	free(comand);
	return (0);
}