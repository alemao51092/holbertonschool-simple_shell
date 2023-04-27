#include "main.h"

char **_path(void)
{
    char *path = get_env("PATH");
    char *ptoken;
    char **ptokens;
    int num =  0;
    int i = 0;

    num  = numcount(path);
    ptokens = _calloc(num + 1, sizeof(char *));
    ptoken = strtok(path, ":");

    while(ptoken)
    {
        ptokens[i] = ptoken;  
        ptoken = strtok(NULL, ":");  
        i++;
        
    }
    return (ptokens);
}