#include "alx.h"

#define TOKEN_DELIM " \t\r\n\a,;|&:"

char **_token(char *str);
size_t count_tokens(char *str, char *delim);
void free_tokens(char **tokens);

/**
 * _token - Parse the arguments passed by the user
 * @str: A pointer to the argument passed by the user
 *
 * Return: tokens of the strings
 */

char **_token(char *str)
{
	char **holder = NULL;
	char *strcopy = NULL;
	size_t num_tokens = 0;

	if (str == NULL)
		return (NULL);

	strcopy = _strdup(str);
	if (strcopy == NULL)
		return (NULL);

	num_tokens = count_tokens(strcopy, TOKEN_DELIM);

	holder = malloc(num_tokens + 1, sizeof(char *));
	if (holder == NULL)
	{
		free(strcopy);
		return (NULL);
	}

	char *token = strtok(strcopy, TOKEN_DELIM);
	size_t i = 0;

	while (token != NULL)
	{
		holder[i] = _strdup(token);
		if (holder[i] == NULL)
		{
			free_tokens(holder);
			free(strcopy);
			return (NULL);
		}
		i++;
		token = strtok(NULL, TOKEN_DELIM);
	}

	free(strcopy);
	return (holder);
}

/**
 * count_tokens - Counts the number of tokens in a string
 * @str: A pointer to the string
 * @delim: A pointer to the delimiters
 * Return: The number of tokens
 */

size_t count_tokens(char *str, char *delim)
{
	char *token;
	size_t count = 0;

	token = strtok(str, delim);

	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delim);
	}

	return (count);
}

/**
 * free_tokens - Frees a token array
 * @tokens: A pointer to the token array
 */

void free_tokens(char **tokens)
{
	if (tokens == NULL)
		(return);

	for (size_t i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}

	free(tokens);
}
