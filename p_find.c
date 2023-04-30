#include "alx.h"

int check_file(char *full_path);

/**
 * prog_fnd - find path
 * @nick: a pointer to struct.
 *
 * Return: 0 if successfull.
 */

int prog_fnd(_st *nick)
{
	int i = 0, ret_code = 0;
	char **directories;

	if (!nick->c)
		return (2);

	if (nick->c[0] == '/' || nick->c[0] == '.')
		return (check_file(nick->c));

	free(nick->f[0]);
	nick->f[0] = str_concat(str_duplicate("/"), nick->c);
	if (!nick->f[0])
		return (2);

	directories = _tok(nick);

	if (!directories || !directories[0])
	{
		errno = 127;
		return (127);
	}
	for (i = 0; directories[i]; i++)
	{
		directories[i] = str_concat(directories[i], nick->f[0]);
		ret_code = check_file(directories[i]);
		if (ret_code == 0 || ret_code == 126)
		{
			errno = 0;
			free(nick->f[0]);
			nick->f[0] = str_duplicate(directories[i]);
			free_array_of_pointers(directories);
			return (ret_code);
		}
	}
	free(nick->f[0]);
	nick->f[0] = NULL;
	free_array_of_pointers(directories);
	return (ret_code);
}


/**
 * _tok - tokenize the path.
 * @nick: a pointer to struct
 *
 * Return: array of the  path
 */

char **_tok(_st *nick)
{
	int i = 0;
	int counter_directories = 2;
	char **tokens = NULL;
	char *PATH;

	/* get the PATH value*/

	PATH = env_get_key("PATH", nick);
	if ((PATH == NULL) || PATH[0] == '\0')
	{
		return (NULL);
	}

	PATH = str_duplicate(PATH);

	for (i = 0; PATH[i]; i++)
	{
		if (PATH[i] == ':')
			counter_directories++;
	}

	/* reserve space for the array of pointers */
	tokens = malloc(sizeof(char *) * counter_directories);

	/*tokenize and duplicate each token of path*/
	i = 0;
	tokens[i] = str_duplicate(_strtok(PATH, ":"));
	while (tokens[i++])
	{
		tokens[i] = str_duplicate(_strtok(NULL, ":"));
	}

	free(PATH);
	PATH = NULL;
	return (tokens);

}

/**
 * check_file - checks if exists a file.
 * @full_path: pointer to the full file name
 *
 * Return: 0 on successfull
 */

int check_file(char *full_path)
{
	struct stat sb;

	if (stat(full_path, &sb) != -1)
	{
		if (S_ISDIR(sb.st_mode) ||  access(full_path, X_OK))
		{
			errno = 126;
			return (126);
		}
		return (0);
	}
	/*if not exist the file*/
	errno = 127;
	return (127);
}
