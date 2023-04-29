#include "alx.h"

/**
 * env_get_key - gets the value of an environment variable
 * @key: the environment variable of interest
 * @nick: struct of the program's data
 * Return: a pointer to the value of the variable or NULL if it doesn't exist
 */
char *env_get_key(char *key, _st *nick)
{
	int i, key_length = 0;

	/* validate the arguments */
	if (key == NULL || nick->env == NULL)
		return (NULL);

	/* obtains the leng of the variable requested */
	key_length = str_length(key);

	for (i = 0; nick->env[i]; i++)
	{/* Iterates through the environ and check for coincidence of the vame */
		if (str_compare(key, nick->env[i], key_length) &&
		 nick->env[i][key_length] == '=')
		{/* returns the value of the key NAME=  when find it*/
			return (nick->env[i] + key_length + 1);
		}
	}
	/* returns NULL if did not find it */
	return (NULL);
}

/**
 * env_set_key - overwrite the value of the environment variable
 * or create it if does not exist.
 * @key: name of the variable to set
 * @value: new value
 * @nick: struct of the program's data
 * Return: 1 if the parameters are NULL, 2 if there is an erroror 0 if sucess.
 */

int env_set_key(char *key, char *value, _st *nick)
{
	int i, key_length = 0, is_new_key = 1;

	/* validate the arguments */
	if (key == NULL || value == NULL || nick->env == NULL)
		return (1);

	/* obtains the leng of the variable requested */
	key_length = str_length(key);

	for (i = 0; nick->env[i]; i++)
	{/* Iterates through the environ and check for coincidence of the vame */
		if (str_compare(key, nick->env[i], key_length) &&
		 nick->env[i][key_length] == '=')
		{/* If key already exists */
			is_new_key = 0;
			/* free the entire variable, it is new created below */
			free(nick->env[i]);
			break;
		}
	}
	/* make an string of the form key=value */
	nick->env[i] = str_concat(str_duplicate(key), "=");
	nick->env[i] = str_concat(nick->env[i], value);

	if (is_new_key)
	{/* if the variable is new, it is create at end of actual list and we need*/
	/* to put the NULL value in the next position */
		nick->env[i + 1] = NULL;
	}
	return (0);
}

/**
 * env_remove_key - remove a key from the environment
 * @key: the key to remove
 * @nick: the sructure of the program's data
 * Return: 1 if the key was removed, 0 if the key does not exist;
 */
int env_remove_key(char *key, _st *nick)
{
	int i, key_length = 0;

	/* validate the arguments */
	if (key == NULL || nick->env == NULL)
		return (0);

	/* obtains the leng of the variable requested */
	key_length = str_length(key);

	for (i = 0; nick->env[i]; i++)
	{/* iterates through the environ and checks for coincidences */
		if (str_compare(key, nick->env[i], key_length) &&
		 nick->env[i][key_length] == '=')
		{/* if key already exists, remove them */
			free(nick->env[i]);

			/* move the others keys one position down */
			i++;
			for (; nick->env[i]; i++)
			{
				nick->env[i - 1] = nick->env[i];
			}
			/* put the NULL value at the new end of the list */
			nick->env[i - 1] = NULL;
			return (1);
		}
	}
	return (0);
}


/**
 * print_environ - prints the current environ
 * @nick: struct for the program's data
 * Return: nothing
 */
void print_environ(_st *nick)
{
	int j;

	for (j = 0; nick->env[j]; j++)
	{
		_print(nick->env[j]);
		_print("\n");
	}
}
