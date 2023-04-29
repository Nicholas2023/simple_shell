#include "alx.h"
/**
 * main - initialize the variables of the program
 * @argc: number of values received from the command line
 * @argv: values received from the command line
 * @env: number of values received from the command line
 * Return: zero on succes.
 */
int main(int argc, char *argv[], char *env[])
{
	_st data_struct = {NULL}, *nick = &data_struct;
	char *prompt = "";

	inicialize_data(nick, argc, argv, env);

	signal(SIGINT, handle_ctrl_c);

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{/* We are in the terminal, interactive mode */
		errno = 2;/*???????*/
		prompt = COMMAND_PROMPT;
	}
	errno = 0;
	sisifo(prompt, nick);
	return (0);
}

/**
 * handle_ctrl_c - print the prompt in a new line
 * when the signal SIGINT (ctrl + c) is send to the program
 * @UN_USED: option of the prototype
 */
void handle_ctrl_c(int opr UNUSED)
{
	_print("\n");
	_print(COMMAND_PROMPT);
}

/**
 * inicialize_data - inicialize the struct with the info of the program
 * @nick: pointer to the structure of data
 * @argv: array of arguments pased to the program execution
 * @env: environ pased to the program execution
 * @argc: number of values received from the command line
 */
void inicialize_data(_st *nick, int argc, char *argv[], char **env)
{
	int i = 0;

	nick->a = argv[0];
	nick->b = NULL;
	nick->c = NULL;
	nick->d = 0;
	/* define the file descriptor to be readed*/
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
 * sisifo - its a infinite loop that shows the prompt
 * @prompt: prompt to be printed
 * @nick: its a infinite loop that shows the prompt
 */
void sisifo(char *prompt, _st *nick)
{
	int error_code = 0, string_len = 0;

	while (++(nick->d))
	{
		_print(prompt);
		error_code = string_len = _getline(nick);

		if (error_code == EOF)
		{
			free_all_data(nick);
			exit(errno); /* if EOF is the fisrt Char of string, exit*/
		}
		if (string_len >= 1)
		{
			expand_alias(nick);
			expand_variables(nick);
			tokenize(nick);
			if (nick->f[0])
			{ /* if a text is given to prompt, execute */
				error_code = execute(nick);
				if (error_code != 0)
					_print_error(error_code, nick);
			}
			free_recurrent_data(nick);
		}
	}
}
