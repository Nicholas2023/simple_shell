#include "alx.h"

/**
 * p_env - print the enviroment
 * @anna: a pointer to the enviroment
 *
 * Return: void
 */

void p_env(char **anna)
{
	size_t  n = 0;
	size_t length;

	while (anna[n])
	{
		/*determine the length of the enviroment variable*/
		length = _strlen(anna[n]);
		/*write the current enviroment standard output*/
		write(STDOUT_FILENO, anna[n], length);
		/*add a new line*/
		_putchar('\n');
		/* move to the next enviroment*/
		n++;
	}
}

/**
 * _getenv - gets env
 * @nick: a pointer that print the env
 * @env: gets env
 *
 * Return: void
 */

void _getenv(char *nick, char **env)
{
	/* checks if the input is equal to the string "env"*/
	if (_strcmp(nick, "env") == 0)
	{
		/*if they are equall call the p_env function to print enviroment variable*/
		p_env(env);
	}
}
