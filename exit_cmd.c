#include "alx.h"

/**
 * builtin_exit - exit of the program with the status
 * @nick: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_exit(_st *nick)
{
	int i;

	if (nick->f[1] != NULL)
	{/*if exists arg for exit, check if is a number*/
		for (i = 0; nick->f[1][i]; i++)
			if ((nick->f[1][i] < '0' || nick->f[1][i] > '9')
				&& nick->f[1][i] != '+')
			{/*if is not a number*/
				errno = 2;
				return (2);
			}
		errno = _atoi(nick->f[1]);
	}
	free_all_data(nick);
	exit(errno);
}

/**
 * builtin_cd - change the current directory
 * @nick: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_cd(_st *nick)
{
	char *dir_home = env_get_key("HOME", nick), *dir_old = NULL;
	char old_dir[128] = {0};
	int error_code = 0;

	if (nick->f[1])
	{
		if (str_compare(nick->f[1], "-", 0))
		{
			dir_old = env_get_key("OLDPWD", nick);
			if (dir_old)
				error_code = set_work_directory(nick, dir_old);
			_print(env_get_key("PWD", nick));
			_print("\n");

			return (error_code);
		}
		else
		{
			return (set_work_directory(nick, nick->f[1]));
		}
	}
	else
	{
		if (!dir_home)
			dir_home = getcwd(old_dir, 128);

		return (set_work_directory(nick, dir_home));
	}
	return (0);
}

/**
 * set_work_directory - set the work directory
 * @nick: struct for the program's data
 * @new_dir: path to be set as work directory
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int set_work_directory(_st *nick, char *new_dir)
{
	char old_dir[128] = {0};
	int err_code = 0;

	getcwd(old_dir, 128);

	if (!str_compare(old_dir, new_dir, 0))
	{
		err_code = chdir(new_dir);
		if (err_code == -1)
		{
			errno = 2;
			return (3);
		}
		env_set_key("PWD", new_dir, nick);
	}
	env_set_key("OLDPWD", old_dir, nick);
	return (0);
}

/**
 * builtin_help - shows the environment where the shell runs
 * @nick: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_help(_st *nick)
{
	int i, length = 0;
	char *van[6] = {NULL};

	van[0] = HELP_INFO_SEARCH;

	/* validate args */
	if (nick->f[1] == NULL)
	{
		_print(van[0] + 6);
		return (1);
	}
	if (nick->f[2] != NULL)
	{
		errno = E2BIG;
		perror(nick->c);
		return (5);
	}
	van[1] = EXIT_HELP_INFO;
	van[2] = ENVIRONMENT_HELP_INFO;
	van[3] = SETENV_HELP_INFO;
	van[4] = UNSETENV_HELP_INFO;
	van[5] = CD_HELP_INFO;

	for (i = 0; van[i]; i++)
	{
		length = str_length(nick->f[1]);
		if (str_compare(nick->f[1], van[i], length))
		{
			_print(van[i] + length + 1);
			return (1);
		}
	}
	/*if there is no match, print error and return -1 */
	errno = EINVAL;
	perror(nick->c);
	return (0);
}

/**
 * builtin_alias - add, remove or show aliases
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_alias(_st *nick)
{
	int i = 0;

	/* if there are no arguments, print all environment */
	if (nick->f[1] == NULL)
		return (print_alias(nick, NULL));

	while (nick->f[++i])
	{/* if there are arguments, set or print each env variable*/
		if (count_characters(nick->f[i], "="))
			set_alias(nick->f[i], nick);
		else
			print_alias(nick, nick->f[i]);
	}

	return (0);
}
