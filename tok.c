#include "alx.h"

char **_token(char *str);
size_t count_tokens(char *str, char *delim);
void free_tokens(char **tokens);


#define TOKEN_DELIM " \t\r\n\a,;|&:"

/**
 * _token - Parse the arguments passed by the user
 * @str: A pointer to the argument passed by the user
 *
 * Return: tokens of the strings
 */

char **_token(char *str)
{
	char **holder = NULL;
	char *str_copy = NULL, *token;
	size_t num_tokens = 0, i = 0;

	if (str == NULL)
		return (NULL);

	str_copy = _strdup(str);
	if (str_copy == NULL)
		return (NULL);

	num_tokens = count_tokens(str_copy, TOKEN_DELIM);

	holder = malloc((num_tokens + 1) * sizeof(char *));
	if (holder == NULL)
	{
		free(str_copy);
		return (NULL);
	}

	token = strtok(str_copy, TOKEN_DELIM);

	while (token != NULL)
	{
		holder[i] = _strdup(token);
		if (holder[i] == NULL)
		{
			free_tokens(holder);
			free(str_copy);
			return (NULL);
		}
		i++;
		token = strtok(NULL, TOKEN_DELIM);
	}

	free(str_copy);
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
	size_t i;

	if (tokens == NULL)
		return;

	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}

	free(tokens);
}
