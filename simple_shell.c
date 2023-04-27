#include "main.h"

int main(void)
{
    char *comand = NULL;
	size_t n = 0;
	char **tokenargv;
    int read = 0;

    while(1)
    {
        if (isatty(0) == 1)
            printf("Ale ~$: ");
        read = getline(&comand,&n, stdin);
		if(read == -1)
		{
		    free(comand);
		    exit(0);
		}
        tokenargv = tokenize(comand);
        if (tokenargv == NULL)
        {
            free(comand);
            free_token(tokenargv);
            exit(0);
        }
        excecute(tokenargv);
        free(tokenargv), tokenargv = NULL;
        if (_strcmp(comand, "exit") == 0)
        {
            free(comand);
            return (0);
        }
    }
    free_token(tokenargv);
    exit(EXIT_SUCCESS);
    return (0);
}