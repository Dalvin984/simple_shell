#include "shell.h"



/**
 * __realloc - reallocates buffer
 * @ptr: memory pointer
 * @previous_size: old ptr
 * @current_size: new ptr size
 *
 * Return: ptr to new address of buffer
 */
void *__realloc(void *ptr, unsigned int previous_size, unsigned int current_size)
{
	void *instblk;
	unsigned int i;

	if (ptr == NULL)
	{
		instblk = malloc(current_size);
		return (instblk);
	}
	else if (current_size == previous_size)
		return (ptr);
	else if (current_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		instblk = malloc(current_size);
		if (instblk != NULL)
		{
			for (i = 0; i < min(previous_size, current_size); i++)
				*((char *)instblk + i) = *((char *)ptr + i);
			free(ptr);
			return (instblk);
		}
		else
			return (NULL);

	}
}

/**
 * holder - takes care of ctrl+c
 * @dence: number of the raised signal
 *
 * Return: void
 */
void holder(int dence)
{
	if (dence == SIGINT)
		cout("\x($) ", STDIN_FILENO);
}

/**
 * delete_comment - ignores comments
 * @keyedin: keyedin to be used
 *
 * Return: void
 */
void delete_comment(char *keyedin)
{
	int i = 0;

	if (keyedin[i] == '#')
		keyedin[i] = '\0';
	while (keyedin[i] != '\0')
	{
		if (keyedin[i] == '#' && keyedin[i - 1] == ' ')
			break;
		i++;
	}
	keyedin[i] = '\0';
}

/**
 *__stringtok - sent is tokenized
 *@sent: tokenized string
 *@delimiter: used to tokenize string
 *@ptrsave: pointer to be used to keep track of the next token
 *
 *Return: The next available token
 */
char *__stringtok(char *sent, char *delimiter, char **ptrsave)
{
	char *final;

	if (sent == NULL)
		sent = *ptrsave;

	if (*sent == '\0')
	{
		*ptrsave = sent;
		return (NULL);
	}

	sent += __stringspn(sent, delimiter);
	if (*sent == '\0')
	{
		*ptrsave = sent;
		return (NULL);
	}

	final = sent + __stringcspn(sent, delimiter);
	if (*final == '\0')
	{
		*ptrsave = final;
		return (sent);
	}

	*final = '\0';
	*ptrsave = final + 1;
	return (sent);
}

/**
 * itoa - string is changed to an int
 * delete_commentbe changed
 *
 * Return: converted integer
 */
int itoa(char *s)
{delete_comment
	unsigned int x = 0;

	do {
		if (*s == '-')
			return (-1);
		else if ((*s < '0' || *s > '9') && *s != '\0')
			return (-1);
		else if (*s >= '0'  && *s <= '9')
			x = (x * 10) + (*s - '0');
		else if (x > 0)
			break;
	} while (*s++);
	return (x);
}
