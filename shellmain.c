#include "shell.h"

	char **controls = NULL;
	char *ln = NULL;
	char *gatesofshell_name = NULL;
	int condition = 0;
/**
 * main - where shell code is executed
 * @argc: counts arguments entered
 * @argv: arguments parsed
 *End of File is implemented
 * error generated 
 * Prints error on Failure
 * Return: for succes , it is 0
 */

int main(int argc __attribute__((unused)), char **argv)
{
	char **cmnow = NULL;
	int i, cincommand = 0;
	size_t p = 0;

	signal(SIGINT, holder);
	gatesofshell_name = argv[0];
	while (1)
	{
		standalone();
		cout(" ($) ", STDOUT_FILENO);
		if (getline(&ln, &p, stdin) == -1)
		{
			free(ln);
			exit(condition);
		}
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

			/* starter -   */
			starter(cmnow, cincommand);
			free(cmnow);
		}
		free(controls);
	}
	free(ln);

	return (condition);
}

	

