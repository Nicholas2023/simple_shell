#include "alx.h"

/**
 * print_alias - add, remove or show aliases
 * @nick: struct for the program's data
 * @alias: name of the alias to be printed
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int print_alias(_st *nick, char *alias)
{
	int i, j, alias_length;
	char buffer[250] = {'\0'};

	if (nick->h)
	{
		alias_length = str_length(alias);
		for (i = 0; nick->h[i]; i++)
		{
			if (!alias || (str_compare(nick->h[i], alias, alias_length)
				&&	nick->h[i][alias_length] == '='))
			{
				for (j = 0; nick->h[i][j]; j++)
				{
					buffer[j] = nick->h[i][j];
					if (nick->h[i][j] == '=')
						break;
				}
				buffer[j + 1] = '\0';
				buffer_add(buffer, "'");
				buffer_add(buffer, nick->h[i] + j + 1);
				buffer_add(buffer, "'\n");
				_print(buffer);
			}
		}
	}

	return (0);
}

/**
 * get_alias - add, remove or show aliases
 * @nick: struct for the program's data
 * @name: name of the requested alias.
 * Return: zero if sucess, or other number if its declared in the arguments
 */
char *get_alias(_st *nick, char *name)
{
	int i, alias_length;

	/* validate the arguments */
	if (name == NULL || nick->h == NULL)
		return (NULL);

	alias_length = str_length(name);

	for (i = 0; nick->h[i]; i++)
	{/* Iterates through the environ and check for coincidence of the varname */
		if (str_compare(name, nick->h[i], alias_length) &&
			nick->h[i][alias_length] == '=')
		{/* returns the value of the key NAME=  when find it */
			return (nick->h[i] + alias_length + 1);
		}
	}
	/* returns NULL if did not find it */
	return (NULL);

}

/**
 * set_alias - add, or override alias
 * @alias_string: alias to be seted in the form (name='value')
 * @nick: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int set_alias(char *alias_string, _st *nick)
{
	int i, j;
	char buffer[250] = {'0'}, *temp = NULL;

	/* validate the arguments */
	if (alias_string == NULL ||  nick->h == NULL)
		return (1);
	/* Iterates alias to find = char */
	for (i = 0; alias_string[i]; i++)
		if (alias_string[i] != '=')
			buffer[i] = alias_string[i];
		else
		{/* search if the value of the alias is another alias */
			temp = get_alias(nick, alias_string + i + 1);
			break;
		}

	/* Iterates through the alias list and check for coincidence of the varname */
	for (j = 0; nick->h[j]; j++)
		if (str_compare(buffer, nick->h[j], i) &&
			nick->h[j][i] == '=')
		{/* if the alias alredy exist */
			free(nick->h[j]);
			break;
		}

	/* add the alias */
	if (temp)
	{/* if the alias already exist */
		buffer_add(buffer, "=");
		buffer_add(buffer, temp);
		nick->h[j] = str_duplicate(buffer);
	}
	else /* if the alias does not exist */
		nick->h[j] = str_duplicate(alias_string);
	return (0);
}
