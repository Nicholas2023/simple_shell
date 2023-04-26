#include "alx.h"

/**
 * _strcmp - Compare two strings
 * @nick: A pointer to the first string
 * @anna: A pointer to the second string
 *
 * Return: 0 if equal and positive or negative
 * number if unmatched characters are found
 */

int _strcmp(char *nick, char *anna)
{
	while ((*nick && *anna) && (*nick == *anna))
	{
		nick++;
		anna++;
	}
	return (*nick - *anna);
}



/**
 *_strlen - Measures string length
 * @anna: A pointer to string to be measured
 *
 * Return: Integer length of the string
 */

int _strlen(char *anna)
{
	int _len = 0;

	while (anna[_len])
		_len++;
	return (_len);
}



/**
 * _putchar - Write character x to stdout
 * @x: The character to be written
 *
 * Return: 0 if successful and -1 for error
 */

int _putchar(char x)
{
	return (write(1, &x, 1));
}


/**
 * _strcpy - Copies string from one variable to another
 * @nick: A pointer to the source string
 * @anna: A pointer to destination string
 *
 * Return: A pointer to destination string
 */

char *_strcpy(char *nick, char *anna)
{
	int i = -1;

	do {
		i++;
		nick[i] = anna[i];
	} while (anna[i] != '\0');

	return (anna);
}


/**
 * _strdup - Allocates space in heap memory
 * @anna: A pointer to a string to allocate memory
 *
 * Return: A pointer to allocated heap memory
 */


char *_strdup(char *anna)
{
	char *ptr;
	int len = 0;

	if (anna == NULL)
		return (NULL);

	while (*anna++)
		len++;
	ptr = malloc(sizeof(char) * (len + 1));

	if (!ptr)
		return (NULL);
	for (len++; len--;)
		ptr[len] = *--anna;
	return (ptr);
}
