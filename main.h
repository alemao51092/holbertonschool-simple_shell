#ifndef _MAINH_
#define _MAINH_

#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<limits.h>
#include<signal.h>

extern char **environ;

char **tokenize(char *comand, int read);
int free_token(char **comand);
void excecute(char **tokenargv);
int _strcmp(char *s1, char *s2);
void *_calloc(unsigned int nmemb, unsigned int size);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int num_count(char *var);
char **_path(void);
char *get_env(char *var);
char **get_comand(char **tokens);

#endif






