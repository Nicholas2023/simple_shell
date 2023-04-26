#include "alx.h"


/**
 * _strcat - Concatenates two strings
 * @nick: A pointer to the source string
 * @anna: A pointer to the destination string
 *
 * Return: A pointer to the concatenated string
 */

char *_strcat(char *nick, char *anna)
{
	int i = 0;
	int d_len = 0;

	while (nick[i++])
		d_len++;
	for (i = 0; anna[i]; i++)
		nick[d_len++] = anna[i];
	return (nick);
}

/**
 * cat - concatenate a string for path
 * @nick: A pointer to the buffer
 * @anna: The bin to append commands
 * @ven: Command to append to bin
 *
 * Return: Concatenated string
 */

char *cat(char *nick, char *anna, char **ven)
{
	_strcat(nick, anna);
	_strcat(nick, "/");
	_strcat(nick, *ven);
	_strcat(nick, "\0");

	return (nick);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}
