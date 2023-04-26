#include "alx.h"

/**
 * _path - get the path of the command
 * @nick: the input of the user
 * @anna: the enviroment to find path
 * Return: status of 1 or 0
 */
int _path(char **nick, char **env)
{
	char *left = NULL, *right = NULL, *path = NULL, *bins, *envdup, *token;
	size_t n, j, len1 = 0, len2 = 0;

	for (n = 0; env[n]; n++)
	{
		envdup = _strdup(env[n]);
		left = _strtok(envdup, "=");
		right = _strtok(NULL, "=");
		if (_strcmp(left, "PATH") == 0)
		{
			bins = right;
			token = _strtok(bins, ": \t");
			for (j = 0; token; j++)
			{
				len1 = _strlen(token);
				len2 = _strlen(nick[0]);
				path = malloc(sizeof(char) * (len1 + len2 + 2));
				path[0] = '\0';
				path = cat(path, token, nick);
				if (access(path, X_OK) == 0)
				{
					if (fork() == 0)
					{
						execve(path, nick, NULL);
						free(path);
					}
					else
						wait(NULL);
					free(path);
					free(envdup);
					return (0);
				}
				token = _strtok(NULL, ": \t");
				free(path);
			}
		}
		free(envdup);
	}
	return (1);
}
