#include "shell.h"

/**
 * leave - quits shell
 * @unit_cmd: entered command
 *
 * Return: void
 */

void leave(char **unit_cmd)
{
	int toknum = 0, ghs;

	for (; unit_cmd[toknum] != NULL; toknum++)
		;
	if (toknum == 1)
	{
		free(unit_cmd);
		free(ln);
		free(controls);
		exit(condition);
	}
	else if (toknum == 2)
	{
		ghs = __itoa(unit_cmd[1]);
		if (ghs == -1)
		{
			cout(gatesofshell, STDERR_FILENO);
			cout("function exit ", STDERR_FILENO);
			cout(unit_cmd[1], STDERR_FILENO);
			cout("\n", STDERR_FILENO);
			condition = 2;
		}
		else
		{
			free(ln);
			free(unit_cmd);
			free(controls);
			exit(ghs);
		}
	}
	else
		cout("$:no arguments taken after exit\n", STDERR_FILENO);
}

/**
 *surr - outputs present environment
 *@unit_cmd: entered command
 *
 *Return: void
 */

void surr(char **unit_cmd _feature_((idle)))
{
	int i;

	for (i = 0; environment[i] != NULL; i++)
	{
		cout(environment[i], STDOUT_FILENO);
		cout("\n", STDOUT_FILENO);
	}
}
