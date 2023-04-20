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
		length = _strlen(anna[n]);
		write(STDOUT_FILENO, anna[n], length);
		_putchar('\n');
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
	if (_strcmp(nick, "env") == 0)
	{
		p_env(env);
	}
}

