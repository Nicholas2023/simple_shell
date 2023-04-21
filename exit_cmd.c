#include "alx.h"


/**
 * s_exit - Exits the shell if user input is exit
 * @anna: A pointer to user input
 *
 * Return: void
 */

void s_exit(char *anna)
{
	/*Check if user input is "exit"*/
	if (_strcmp(anna, "exit") == 0)
	{
		/*Free Memory due to getline*/
		free(anna);

		/*Exit the shell with an exit status*/
		exit(EXIT_SUCCESS);
	}
}
