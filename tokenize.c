#include "main.h"
/**
 * tokenize - main function
 * Return: tokens
 * @comand: cadena a cortar
*/
char **tokenize(char *comand)
{
	char *token;
	char **tokens;
	int num = 0;
	int i = 0;

	num = numcount(comand);
	tokens = _calloc(num + 1, sizeof(char *));
	if (!tokens)
	{
		free(tokens);
		return (0);
	}
	token = strtok(comand, "      \n");
	while (token)
	{
		tokens[i] = token;
		token = strtok(NULL, "	 \n");
		i++;
	}
	return (tokens);
}
/**
 * free_token - main function
 * Return: 0
 * @comand: cadena a liberar
*/
int free_token(char **comand)
{
	int x;

	if (!comand)
		return (0);

	for (x = 0; comand[x] != NULL; x++)
		free(comand[x]);
	free(comand);
	comand = NULL;
	return (0);
}
/**
 * numcount - main function
 * Return: i
 * @var: ch
*/
int numcount(char *var)
{
	int i = 0;
	char *aux;
	char *sub = strdup(var);

	aux = strtok(sub, " :	\n");
	while (aux)
	{
		aux = strtok(NULL, ":    \n");
		i++;
	}
	free(sub);
	return (i);
}
