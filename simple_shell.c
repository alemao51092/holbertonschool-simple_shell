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
		    printf("\n");
		    exit (1);
		}
        tokenargv = tokenize(comand, read);
        if (tokenargv == NULL)
        {
            free(comand);
            free_token(tokenargv);
            exit(0);
        }
        excecute(tokenargv);
        free_token(tokenargv), tokenargv = NULL;
        

    }
}