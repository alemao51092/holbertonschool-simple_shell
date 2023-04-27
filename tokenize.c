#include "main.h"

char **tokenize(char *comand)
{
	char *token;
	char **tokens;
	int num = 0;
	int i = 0;

	num = numcount(comand);
	tokens = _calloc(num + 1, sizeof(char *));
	if (!tokens)
		return (0);
	token = strtok(comand, "      \n");
	while (token)
	{
		tokens[i] = token;
		token = strtok(NULL, "	 \n");
		i++;
	}
	return (tokens);
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

int numcount(char *var)
{
	int i = 0;
	char *aux; /* Se declara un puntero "aux" para ir guardando cada token (subcadena) de la cadena "var".*/
	char *sub = strdup(var);/* Se hace una copia de la cadena "var" para no alterar la original.*/

	aux = strtok(sub, " :	\n");
	while (aux)
	{
		aux = strtok(NULL, ":    \n");
		i++;
	}
	free(sub);
	return (i);
}