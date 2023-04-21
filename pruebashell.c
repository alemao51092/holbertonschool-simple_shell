
#include "main.h"


int main(void)
{
        char *comand = NULL;
        size_t n = 0;
        int read;
        char *token;


        while (1)
        {
                printf("Ale ~$: ");
                read = getline(&comand,&n, stdin);
                if(read == -1)
                {
                    printf("\n");
                    exit (1);
                }
                token = strtok (comand, " ");
                while (token != NULL)
                {
                        printf("%s", token);
                        token = strtok(NULL," ");

                }
        }
        free(comand);
        return (0);
}