#ifndef _MAINH_
#define _MAINH_

#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

char **tokenize(char *comand, int read);
int free_token(char **comand);
void excecute(char **tokenargv);

#endif






