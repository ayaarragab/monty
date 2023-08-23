#include "monty.h"
/**
 * is_opcode - checks if the given command is valid opcode
 * @cmd: command to be checked
 * Return: pointer to function
 */
void (*is_opcode(char *cmd))(stack_t **stack, unsigned int L)
{
	int i;
	instruction_t opcodes[] = {
		{"pop", pop},
		{"pint", pint},
		{"pall", pall},
		{"swap", swap},
		{"nop", nop},
		{"add", add},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{"sub", sub},
		{"divi", divi},
		{"mod", mod},
		{"mul", mul},
		{NULL, NULL},
	};

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(cmd, opcodes[i].opcode) == 0)
			return (opcodes[i].f);
	}
	return (NULL);
}

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
/**
 * trim - delete the spaces around string
 * @command: command
 * Return: command
*/
char *trim(char *command)
{
	char *end;

	while (isspace((unsigned char)*command))
		command++;
	if (*command == 0)
		return (command);
	end = command + strlen(command) - 1;
	while (end > command && isspace((unsigned char)*end))
		end--;
	*(end + 1) = '\0';
	return (command);
}
