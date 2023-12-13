#include "shell.h"

/**
 *__stringcmp - compare two strings
 *@f: f string to be compared
 *@sec: sec string to be compared
 *
 * Return: difference of the two strings
 */

int __stringcmp(char *f, char *sec)
{
	int i = 0;

	while (f[i] != '\0')
	{
		if (f[i] != sec[i])
			break;
		i++;
	}
	return (f[i] - sec[i]);
}

/**
 *__stringcat - two strings are concanated
 *@station: string to be concanate to
 *@origin:  string to concatenate
 *
 * Return: new string'strng address
 */

char *__stringcat(char *station, char *origin)
{
	char *strnew =  NULL;
	int lnstation = _strlen(station);
	int lnorigin = _strlen(origin);

	strnew = malloc(sizeof(*strnew) * (lnstation + lnorigin + 1));
	_strcpy(station, strnew);
	_strcpy(origin, strnew + lnstation);
	strnew[lnstation + lnorigin] = '\0';
	return (strnew);
}

/**
 *__stringchr - locates a char in a string
 *@strng: searched string
 *@character: checked char
 *
 *Return: pointer to the f occurence of character in strng
 */

char *__stringchr(char *strng, char character)
{
	int i = 0;

	for (; strng[i] != character && strng[i] != '\0'; i++)
		;
	if (strng[i] == character)
		return (strng + i);
	else
		return (NULL);
}


/**
 *__stringspn - finds length of substring
 *@firststring: searched string
 *@secondstring: used string
 *
 *Return: count of bytes in the substring
 */

int __stringspn(char *firststring, char *secondstring)
{
	nt perfect = 0;
    int i = 0;

	while (firststring[i] != '\0')
	{
		if (__stringchr(secondstring, firststring[i]) == NULL)
			break;
		perfect++;
		i++;
	}
	return (perfect);
}

/**
 *__stringcspn - segments of firststring are computed
 *@firststring: searched string
 *@secondstring: used string
 *
 *Return: index of ch in secondstring
 */


int __stringcspn(char *firststring, char *secondstring)
{
	int len = 0, i;

	for (i = 0; firststring[i] != '\0'; i++)
	{
		if (__stringchr(secondstring, firststring[i]) != NULL)
			break;
		len++;
	}
	return (len);
}
