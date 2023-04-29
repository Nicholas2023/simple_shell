#include "alx.h"i


/**
 * builtins_list - a program that execute builtin
 * @nick: a pointer to struct
 *
 * Return: Return a function value,otherwise returns -1.
 **/

int builtins_list(_st *nick)
{
	int iterator;
	builtins options[] = {
		{"exit", builtin_exit},
		{"help", builtin_help},
		{"cd", builtin_cd},
		{"alias", builtin_alias},
		{"env", builtin_env},
		{"setenv", builtin_set_env},
		{"unsetenv", builtin_unset_env},
		{NULL, NULL}
	};
	
	/*the structure*/

	for (iterator = 0; options[iterator].builtin != NULL; iterator++)
	{
		if (str_compare(options[iterator].builtin, nick->c, 0))
		{
			/* execute a function */

			return (options[iterator].function(nick));
		}
	}
	return (-1);
}
