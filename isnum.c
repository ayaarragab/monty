#include "monty.h"

/**
 * isnum - check if the argument is integer
 * @num: number to be checked
 * Return: 1 if is number, 0 otherwise
 */
int isnum(char *num)
{
	int i = 0;

	if (num == NULL || num[0] == '\0')
		return (0);
	while (num[i] != '\0')
	{
		if (isdigit(num[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
