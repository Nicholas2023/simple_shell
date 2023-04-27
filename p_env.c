#include "alx.h"

/**
 * execute - Executes programs
 * @command: User input
 * @buffer: A copy of user's command
 */

void execute(char **command, char *buffer)
{
	if (fork() == 0)
	{
		execve(command[0], command, NULL);
		free(command);
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	else
		wait(NULL);
}
