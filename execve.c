#include "alx.h"

/**
 * _execve - A function that executes in the main shell
 * @nick: A pointer to the command to be executed
 * @anna: A pointer to an array of parsed user arguments
 *
 * Return: void
 */


void _execve(char **nick, char *anna)
{
	pid_t pid;
	int status;

	/*Create child process*/
	pid = fork();

	/*Check if child process was created*/
	if (pid == -1)
	{
		perror("Error: failed to create child process");
		exit(EXIT_FAILURE);
	}
	/*Execute program*/
	else if (pid == 0)
	{
		/*Check for failure in the execve()*/
		if (execve(nick[0], nick, NULL) == -1)
		{
			perror("Error: failed to execute command")
				exit(EXIT_FAILURE);
		}
	}
	else
	{
		/*Wait for the child process to terminate*/
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("Error: failed to wait for child process");
			exit(EXIT_FAILURE);
		}

		/*Freeing memory*/
		if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS)
		{
			free(nick);
			free(anna);
		}
	}
}
