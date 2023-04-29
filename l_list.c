#include "alx.h"


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
		{"exit", blt_in_ext},
		{"help", blt_in_hlp},
		{"cd", blt_in_cd},
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
