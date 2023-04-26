#include "main.h"

char *get_env(char *var)
{
	char **env = environ;
	int x = 0, y, con = 0, len;
	char *path = NULL;

	path = var;
	if (var == NULL || !var[x])
		return (NULL);
	len = _strlen(path);
	while (*(environ + x))
	{
		y = 0;
		while (*(*(env + x) + y) != '=')
		{
			if (*(*(env + x) + y) == var[y])
				con++;
			y++;
		}
		if (con == len)
		{
			y++;
			return (*(environ + x) + y);
		}
		x++;
		con = 0;
	}
	return (0);
}