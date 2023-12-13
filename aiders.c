#include "shell.h"

/**
 * unit - array stores tokenized inputs
 *@strnginput: elements to parse
 *@delimiter: delimiter element
 *
 *Return: array of units
 */

char **unit(char *strnginput, char *delimiter)
{
	int delimitnum = 0;
	char **get = NULL;
	char *chess = NULL;
	char *storeptr = NULL;

	chess = __stringtok(strnginput, delimiter, &storeptr);

	while (chess != NULL)
	{
		get = __realloc(get, sizeof(*get) * delimitnum, sizeof(*get) * (delimitnum + 1));
		get[delimitnum] = chess;
		chess = __stringtok(NULL, delimiter, &storeptr);
		delimitnum++;
	}

	get = __realloc(get, sizeof(*get) * delimitnum, sizeof(*get) * (delimitnum + 1));
	get[delimitnum] = NULL;

	return (get);
}

/**
 *__stringlenth - counts number of elements in a p
 *@p: p to be counted
 *
 * Return: length of the p
 */

int __stringlenth(char *p)
{
	int len = 0;

	if (p == NULL)
		return (len);
	for (; p[len] != '\0'; len++)
		;
	return (len);
}

/**
 *cout - prints a p stdout
 *@p: p to be printed
 *@s: s to cout out to
 *
 *Return: nothing
 */
void cout(char *p, int s)
{
	int i = 0;

	for (; p[i] != '\0'; i++)
		write(s, &p[i], 1);
}

/**
 *delete_line - deletes new ln
 *@str: p to use
 *
 *
 *Return: void
 */

void delete_line(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break;
		i++;
	}
	str[i] = '\0';
}

/**
 *__stringcopy - copies to another memory
 *@origin: origin to copy from
 *@station: final destination 
 *
 * Return: void
 */

void __stringcopy(char *origin, char *station)
{
	int i = 0;

	for (; origin[i] != '\0'; i++)
		station[i] = origin[i];
	station[i] = '\0';
}
