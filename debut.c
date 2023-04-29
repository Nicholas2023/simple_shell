#include "alx.h"


/**
 * main - Entry point of the shell program
 * @argc: Number of CL arguments
 * @argv: Command line arguments
 * @env: Environment variables
 *
 * Return: 0 is successfull
 */


int main(int argc, char *argv[], char *env[])
{
	_st data_struct = {NULL}, *nick = &data_struct;
	char *prompt = "";

	kimba(nick, argc, argv, env);
	signal(SIGINT, handle_ctrl_c);
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{
		/* Command prompt*/
		errno = 2;
		prompt = COMMAND_PROMPT;
	}
	errno = 0;
	muturi(prompt, nick);
	return (0);
}

/**
 * handle_ctrl_c - A function that prints the CMD PROMPT
 * @UNUSED: option of the prototype
 *
 */
void handle_ctrl_c(int opr UNUSED)
{
	_print("\n");
	_print(COMMAND_PROMPT);
}


/**
 * kimba - A func that initializes the struct
 * @nick: pointer to struct data
 * @argv: Array pointer to user input 
 * @env: env variables
 * @argc: Number of arguments for the CLI
 *
 */


void kimba(_st *nick, int argc, char *argv[], char **env)
{
	int i = 0;

	nick->a = argv[0];
	nick->b = NULL;
	nick->c = NULL;
	nick->d = 0;
	
	if (argc == 1)
		nick->e = STDIN_FILENO;
	else
	{
		nick->e = open(argv[1], O_RDONLY);
		if (nick->e == -1)
		{
			_printe(nick->a);
			_printe(": 0: Can't open ");
			_printe(argv[1]);
			_printe("\n");
			exit(127);
		}
	}
	nick->f = NULL;
	nick->env = malloc(sizeof(char *) * 50);
	if (env)
	{
		for (; env[i]; i++)
		{
			nick->env[i] = str_duplicate(env[i]);
		}
	}
	nick->env[i] = NULL;
	env = nick->env;

	nick->h = malloc(sizeof(char *) * 20);
	for (i = 0; i < 20; i++)
	{
		nick->h[i] = NULL;
	}
}



/**
 * muturi - A func that prints CMD PROMPT infinitely
 * @prompt: A pointer to Shell prompt 
 * @nick: A pointer to struct
 *
 */


void muturi(char *prompt, _st *nick)
{
	int error_code = 0, string_len = 0;

	while (++(nick->d))
	{
		_print(prompt);
		error_code = string_len = _getline(nick);

		if (error_code == EOF)
		{
			free_all_data(nick);
			exit(errno);
		}
		if (string_len >= 1)
		{
			expand_alias(nick);
			expand_variables(nick);
			tokenize(nick);
			if (nick->f[0])
			{
				error_code = execute(nick);
				if (error_code != 0)
					_print_error(error_code, nick);
			}
			free_recurrent_data(nick);
		}
	}
}
