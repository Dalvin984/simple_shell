#include "shell.h"

/**
 * performcommand - performs a specific command type
 * @unitcm: control that's tokenized
 * @ctrltype: control type
 *
 * Return: void
 */
void performcommand(char **unitcm, int ctrltype)
{
	void (*func)(char **control);

	if (ctrltype == EXTERNAL_COMMAND)
	{
		if (execve(unitcm[0], unitcm, NULL) == -1)
		{
			perror(fetchenvironment("PWD"));
			exit(2);
		}
	}
	if (ctrltype == PATH_COMMAND)
	{
		if (execve(accesspath(unitcm[0]), unitcm, NULL) == -1)
		{
			perror(fetchenvironment("PWD"));
			exit(2);
		}
	}
	if (ctrltype == INTERNAL_COMMAND)
	{
		func = findfunction(unitcm[0]);
		func(unitcm);
	}
	if (ctrltype == INVALID_COMMAND)
	{
		cout(gatesofshell_name, STDERR_FILENO);
		cout(": 1: ", STDERR_FILENO);
		cout(unitcm[0], STDERR_FILENO);
		cout(": not found\n", STDERR_FILENO);
		condition = 127;
	}
}

/**
 * accesspath - examines if a command is on path
 * @control: implemented command
 *
 * Return: pathfound
 */
char *accesspath(char *control)
{
	char **arrpth = NULL;
	char *way = fetchenvironment("PATH");
	int i;
    char *jump, *fall, *copypath;

	if (way == NULL || __stringlength(way) == 0)
		return (NULL);
	copypath = malloc(sizeof(*copypath) * (__stringlength(way) + 1));
	_strcpy(way, copypath);
	arrpth = unit(copypath, ":");
	for (i = 0; arrpth[i] != NULL; i++)
	{
		fall = __stringcat(arrpth[i], "/");
		jump = __stringcat(fall, control);
		if (access(jump, F_OK) == 0)
		{
			free(fall);
			free(arrpth);
			free(copypath);
			return (jump);
		}
		free(jump);
		free(fall);
	}
	free(copypath);
	free(arrpth);
	return (NULL);
}

/**
 * fetchenvironment - finds value of env
 * @detail: detail of the environment variable
 *
 * Return: the value of the variable as a string
 */
char *fetchenvironment(char *detail)
{
	char **personalenv;
	char *cate;
	char *detailcp;

	for (personalenv = environ; *personalenv != NULL; personalenv++)
	{
		for (cate = *personalenv, detailcp = detail;
		     *cate == *detailcp; cate++, detailcp++)
		{
			if (*cate == '=')
				break;
		}
		if ((*cate == '=') && (*detailcp == '\0'))
			return (cate + 1);
	}
	

/** controlparse - identifies control type
 * @control: parsed control
 *
 * Return: type of control
 * Description -
 *       INVALID_COMMAND (-1) represents invalid commands
 * 		 EXTERNAL_COMMAND (1) represents commands like /bin/ls
 *       PATH_COMMAND (3) represents commands found in the PATH like ls
 *		 INTERNAL_COMMAND (2) represents commands like leaving, environment
 *		  
 */

int controlparse(char *control)
{
	int i;
	char *cminter[] = {"environment", "leaving", NULL};
	char *way = NULL;

	for (i = 0; control[i] != '\0'; i++)
	{
		if (control[i] == '/')
			return (EXTERNAL_COMMAND);
	}
	for (i = 0; cminter[i] != NULL; i++)
	{
		if (__stringcmp(control, cminter[i]) == 0)
			return (INTERNAL_COMMAND);
	}
	/* @accesspath - examines if  a  command is found */
	way = accesspath(control);
	if (way != NULL)
	{
		free(way);
		return (PATH_COMMAND);
	}

	return (INVALID_COMMAND);
}


/**
 * findfunction - finds a function
 * @control: string to counter check from
 *
 * Return: ptr to function
 */
void (*findfunction(char *control))(char **)
{
	int i;
	function_map cap[] = {
		{"surr", surr}, {"exit", leave}
	};

	for (i = 0; i < 2; i++)
	{
		if (__stringcmp(control, cap[i].command_name) == 0)
			return (cap[i].func);
	}
	return (NULL);
}

return (NULL);
}
