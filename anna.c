#include "alx.h"

/**
 * builtin_env - shows the environment where the shell runs
 * @nick: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_env(_st *nick)
{
	int i;
	char cpname[50] = {'\0'};
	char *var_copy = NULL;

	/* if not arguments */
	if (nick->f[1] == NULL)
		print_environ(nick);
	else
	{
		for (i = 0; nick->f[1][i]; i++)
		{/* checks if exists a char = */
			if (nick->f[1][i] == '=')
			{/* checks if exists a var with the same name and change its value*/
			/* temporally */
				var_copy = str_duplicate(env_get_key(cpname, nick));
				if (var_copy != NULL)
					env_set_key(cpname, nick->f[1] + i + 1, nick);

				/* print the environ */
				print_environ(nick);
				if (env_get_key(cpname, nick) == NULL)
				{/* print the variable if it does not exist in the environ */
					_print(nick->f[1]);
					_print("\n");
				}
				else
				{/* returns the old value of the var*/
					env_set_key(cpname, var_copy, nick);
					free(var_copy);
				}
				return (0);
			}
			cpname[i] = nick->f[1][i];
		}
		errno = 2;
		perror(nick->c);
		errno = 127;
	}
	return (0);
}

/**
 * builtin_set_env - ..
 * @nick: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_set_env(_st *nick)
{
	/* validate args */
	if (nick->f[1] == NULL || nick->f[2] == NULL)
		return (0);
	if (nick->f[3] != NULL)
	{
		errno = E2BIG;
		perror(nick->c);
		return (5);
	}

	env_set_key(nick->f[1], nick->f[2], nick);

	return (0);
}

/**
 * builtin_unset_env - ..
 * @nick: struct for the program's data'
 * Return: ..
 */
int builtin_unset_env(_st *nick)
{
	/* validate args */
	if (nick->f[1] == NULL)
		return (0);
	if (nick->f[2] != NULL)
	{
		errno = E2BIG;
		perror(nick->c);
		return (5);
	}
	env_remove_key(nick->f[1], nick);

	return (0);
}
