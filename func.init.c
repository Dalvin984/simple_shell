#include "shell.h"

/**
 * starter - everything is executed from the beginning
 * @cmnow: current token is checked
 * @cincommand: token parsed
 *
 * Return: void 
 */

void starter(char **cmnow, int cincommand)
{
	pid_t PID;

	if (cincommand == EXTERNAL_COMMAND || cincommand == PATH_COMMAND)
	{
		PID = fork();
		if (PID == 0)
			performcommand(cmnow, cincommand);
		else
		{
			waitpid(PID, &condition, 0);
			condition >>= 8;
		}
	}
	else
		performcommand(cmnow, cincommand);
}
