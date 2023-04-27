#include "alx.h"
/**
 *tokens - will tokenize the arguments passed by the user
 *@str: is the argument passed by the user
 *Return: holder
 */
char **tokens(char *str)
{
	char *token;
	char **holder = NULL;
	char *strcopy = NULL;
	size_t j, counter;

	j = 0, counter = 0;
	strcopy = _strdup(str);
	token = strtok(strcopy, " ");
	while (token)
	{
		token = strtok(NULL, " ");
		counter++;
	}
	holder = malloc(sizeof(char *) * (counter + 1));
	if (holder == NULL)
		free(holder);
	holder[0] = "\0";
	token = strtok(str, " ");
	while (token)
	{
		holder[j] = token;
		token = strtok(NULL, " ");
		j++;
	}
	holder[counter] = NULL;
	free(strcopy);
	strcopy = NULL;
	return (holder);
}
