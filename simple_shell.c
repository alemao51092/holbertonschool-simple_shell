#include "main.h"
/**
 * main - basic shell project
 * Return: 0
*/
int main(void)
{
	char *comand = NULL;
	size_t n = 1024;
	char **tokenargv = NULL;
	int read = 0;
	int status = 0;

	while (1)
	{
		if (isatty(0) == 1)
			printf("Ale ~$: ");
		read = getline(&comand, &n, stdin);
		if (read == -1 || _strcmp(comand, "exit\n") == 0)
		{
			free(comand);
			exit(0);
		}
		tokenargv = tokenize(comand);
		if (_strcmp(tokenargv[0], "env") == 0)
		{
			print_env();
			free(tokenargv);
			continue;
		}
		if (tokenargv == NULL)
		{
			free(comand);
			free_token(tokenargv);
			exit(0);
		}
		excecute(tokenargv);
		free(tokenargv), tokenargv = NULL;
	}
	free_token(tokenargv);
	return (status);
}
