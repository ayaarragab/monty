#include "monty.h"

/**
 * is_comment - check if the line is comment
 * @line: line from buffer
 * Return: 1 if line is comment, 0 otherwise
 */
int is_comment(char *line)
{
	int i = 0;

	while (line[i] != '\0')
	{
		if (isspace(line[i]))
			i++;
		else if (line[i] == '#')
			return (1);
		else
			return (0);
		i++;
	}
	return (0);
}
