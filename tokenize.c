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

int num_count(char *var)
{
	int i = 0;
	char *aux; // Se declara un puntero "aux" para ir guardando cada token (subcadena) de la cadena "var".
	char *sub = strdup(var);// Se hace una copia de la cadena "var" para no alterar la original.

	aux = strtok(sub, " :	\n");
	while (aux)
	{
		aux = strtok(NULL, ":    \n");
		i++;
	}
	free(sub);
	return (i);
}