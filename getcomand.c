#include "main.h"
/**
 * get_comand - main function
 * Return: 0
 * @tokens: cadena de comandos
*/

char **get_comand(char **tokens)
{
	 char *ccopy;
	 char **path = _path();
	 char *function = NULL;
	 int i = 0;
	 struct stat buffer;

	if (!stat(tokens[0], &buffer))
		return (tokens);

	while (path[i])
	{
		ccopy = tokens[0];
		function = _calloc(_strlen(path[i]) + _strlen(ccopy) + 2, sizeof(char));
		if (!function)
		{
			free(path);
			perror("Error");
			exit(EXIT_FAILURE);
		}
		strcpy(function, path[i]);
		strcat(function, "/");
		strcat(function, ccopy);
		if (!stat(function, &buffer))
		{
			tokens[0] = function;
			return (tokens);
		}
		i++;
		free(function), function = NULL;
	}
	free(tokens);
	free_token(path);
	free(function);

	return (0);

}
