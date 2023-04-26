#include "alx.h"


int toklen(char *str, char *dlm);
int num_tokens(char *str, char *dlm);
char *_strtok(char *input, char *dlm);

/**
 * toklen - Finds the last delimeter index
 * @str: The string to be measured
 * @dlm: The delimeter
 *
 * Return: The last delimeter index of a str
 */

int toklen(char *str, char *dlm)
{
	int i = 0, length = 0;

	while (*(str + i) && *(str + i) != *dlm)
	{
		length++;
		i++;
	}

	return (length);
}


/**
 * num_tokens - Counts number of tokens in a string
 * @str: The string to be split
 * @dlm: A pointer to delimeters
 *
 * Return: The number of tokens in searched string
 */

int num_tokens(char *str, char *dlm)
{
	int i, tok = 0, len = 0;

	for (i = 0; *(str + i); i++)
		len++;

	for (i = 0; i < len; i++)
	{
		if (*(str + i) != *dlm)
		{
			tok++;
			i += toklen(str + i, dlm);
		}
	}
	return (tok);
}



/**
 * _strtok - A function that tokenizes a string
 * @input: A pointer to the string to be parsed
 * @dlm: The delimeter characters used to tokenize the string
 *
 * Return: A ponter to an array of tokens
 */

char *_strtok(char *input, char *dlm)
{
	char *str;
	int index = 0, tokens, t, letters, l;

	tokens = num_tokens(input, dlm);
	if (tokens == 0)
		return (NULL);

	str = malloc(sizeof(char *) * (tokens + 2));
	if (!str)
		return (NULL);

	for (t = 0; t < tokens; t++)
	{
		while (input[index] == *dlm)
			index++;

		letters = toklen(input + index, dlm);

		str[t] = malloc(sizeof(char) * (letters + 1));
		if (!str[t])
		{
			for (index -= 1; index >= 0; index--)
				free(str[index]);
			free(str);
			return (NULL);
		}

		for (l = 0; l < letters; l++)
		{
			str[t][l] = input[index];
			index++;
		}

		str[t][l] = '\0';
	}
	str[t] = NULL;
	str[t + 1] = NULL;

	return (str);
}
