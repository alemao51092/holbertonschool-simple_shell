#include "main.h"
#include <sys/wait.h>

int excecute(char **tokenargv)
{
	pid_t w, newpid;
	char **function;
	int status;
	
	newpid = fork();

	if (newpid == -1)
	{
		perror("./shell");
		exit(EXIT_FAILURE);
	}
	else if (newpid == 0)
	{
		function = get_comand(tokenargv);

		if (execve(function[0], function, environ) == -1)
		{
			free(tokenargv);
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else
	{
        do 
        {
			w = waitpid(newpid, &status, WUNTRACED);
			
			if (w == -1)
				exit(EXIT_FAILURE);
			
			if (WIFSTOPPED(status))
			{
				printf("Proceso suspendido con el código %d\n", WSTOPSIG(status));
				
				kill(newpid, SIGCONT);
			}
        }
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
        
    }
	return (status);
}