#include "alx.h"
/**
 *printenvi - is a built-in that will print the enviroment
 *@env: is the enviroment
 *Return: void
 */
void printenvi(char **env)
{
	size_t i = 0;
	size_t len;

	while (env[i])
	{
		len = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], len);
		_putchar('\n');
		i++;
	}
}
/**
 *_env - is a helper function that gets the env
 *@str: prints the env
 *@env: gets the env
 *Return: void
 */
void _env(char *str, char **env)
{
	if (_strcmp(str, "env") == 0)
	{
		printenvi(env);
	}
}
