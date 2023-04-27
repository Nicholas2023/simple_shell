#include "alx.h"

/**
 *exitshell - will exit the shell when the word exit is entered by the user
 *@buffer: takes the arg from the user
 *Return: void
 */
void exitshell(char *buffer)
{
	if (_strcmp(buffer, "exit") == 0)
	{
		free(buffer);
		exit(EXIT_SUCCESS);
	}
}
