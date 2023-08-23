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
