#include "shell.h"

/**
 * standalone - takes care of noninteractive mode
 *
 * Return: void
 */

void standalone(void)
{
	char **cmnow = NULL;
	int i, cincommand = 0;
	size_t n = 0;

	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&ln, &n, stdin) != -1)
		{
			delete_line(ln);
			delete_comment(ln);
			controls = unit(ln, ";");
			for (i = 0; controls[i] != NULL; i++)
			{
				cmnow = unit(controls[i], " ");
				if (cmnow[0] == NULL)
				{
					free(cmnow);
					break;
				}
				cincommand = controlparse(cmnow[0]);
				starter(cmnow, cincommand);
				free(cmnow);
			}
			free(controls);
		}
		free(ln);
		exit(condition);
	}
}
