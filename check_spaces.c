#include "monty.h"
/**
 * check_if_all_spaces - checks if the line contains only spaces
 * @command: command str
 * Return: 0 if all spaces, 1 if not all
 */
int check_if_all_spaces(char *command)
{
	int cntr;
	static size_t sp;

	sp = 0;
	cntr = 0;
	if (command[cntr] == ' ')
	{
		while (command[sp])
			if (isspace((unsigned char)command[sp]))
				sp++;
			else
				break;
		cntr++;
	}
	if (sp == strlen(command))
		return (0);
	return (1);
}
