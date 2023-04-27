#include "alx.h"

/**
 * main - The entry point of the program
 * @ac: the number of arguments passed to the program
 * @av: arguments passed to the program
 * @env: an array of strings that contains the enviroment variables
 *
 * Return: 0 for successful execution of the program
 */


int main(int ac, char **av, char **env)
{
	char *input_buffer = NULL, **command = NULL;
	ssize_t buffer_size = 0, read_char = 0;
	int status = 0, i = 0, tally = 0;

	(void)ac, (void)av; /* Silence warnings about unused parameters */

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2); /* print shell prompt */
		read_char = getline(&input_buffer, &buffer_size, stdin);
		if (read_char == EOF)
			break;
		if (_strcmp(input_buffer, "\n") == 0)
			continue; /* skip empty input */
		if (_strcmp(input_buffer, "\t") == 0)
			continue;
		for (; input_buffer[i] != '\0'; i++) /* Remove newline */
		{
			if (input_buffer[i] == '\n')
				input_buffer[i] = '\0';
		}
		_getenv(input_buffer, env); /* Exit status in case of "$?" */
		s_exit(input_buffer); /* Use exit command */
		command = _token(input_buffer); /* Tokenize buffer */
		if (command == NULL)
			continue;
		status = _path(command, env); /* Find command path */
		if (status == 1)
			_execve(command, input_buffer); /* Execute command if found */
		free(command), free(input_buffer), input_buffer = NULL, tally++;
	}
	return (0);
}
