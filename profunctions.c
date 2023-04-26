#include "main.h"

/**
 * _strlen - main function
 * Description: length
 * @s: Char
 * Return: i
 */
int _strlen(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
		i++;
	return (i);
}

char *_strcat(char *dest, char *src)
{
	int i = 0;
	int x = 0;
	char *j = dest;


	while (dest[i])
		i++;

	while (src[x])
	{

	dest[i] = src[x];
		i++;
		x++;
	}
	return (j);
}

/**
 * _strcmp - main function
 * @s1: char
 * @s2: char3
 * Description: compare
 * Return: 0
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
/**
 * _calloc - main function
 * Description: calloc
 * @nmemb: ch1
 * @size: ch2
 * Return: pointer
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;
	unsigned int count;
	unsigned int tam = nmemb * size;

	if (nmemb == 0 || size == 0)
		return (NULL);
	p = malloc(tam);
	if (p == NULL)
		return (NULL);

	for (count = 0; count < tam; count++)
		p[count] = 0;
	return (p);
}
/**
 * _strcpy - main function
 * Description: copy
 * @dest: char
 * @src: ch
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}