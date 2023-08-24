#include "monty.h"
/**
 * error_instruction - when an unknown instruction
 * @stack: stack
 * @line: line_number
 * @instr: instruction
 * @buf: buffer
 * Return: nothing
*/
void error_instruction(stack_t **stack, int line, char *instr)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line, instr);
	free_2d();
	free_stack(stack);
	if (info.monty_file)
		fclose(info.monty_file);
	exit(EXIT_FAILURE);
}
/**
 * errno_argc - argc error
 * @stack: stack
 * Return: nothing
*/
void errno_argc(stack_t **stack)
{
	fprintf(stderr, "USAGE: monty file\n");
	free_stack(stack);
	free_2d();
	if (info.monty_file)
		fclose(info.monty_file);
	exit(EXIT_FAILURE);
}
/**
 * errno_fd - fd error
 * @str: filename
 * @stack: stack
 * Return: nothing
*/
void errno_fd(char *str, stack_t **stack)
{
	fprintf(stderr, "Error: Can't open file %s\n", str);
	free_stack(stack);
	free_2d();
	if (info.monty_file)
		fclose(info.monty_file);
	exit(EXIT_FAILURE);
}

/**
 * make_array_of_strings - func
 * @command: command entered
 * Return: array of strings
 */
char **make_array_of_strings(char *command)
{
	char *token;
	char **tokens = malloc(BUFSIZ * sizeof(char *));
	int num_tokns = 0, i;

	token = strtok(command, " ");

	if (tokens == NULL || token == NULL)
		return (NULL);

	while (token != NULL)
	{
		tokens[num_tokns] = malloc(sizeof(token));
		if (tokens[num_tokns] == NULL)
			return (NULL);
		strcpy(tokens[num_tokns], token);
		if (tokens[num_tokns] == NULL)
		{
			for (i = 0; i < num_tokns; i++)
				free(tokens[i]);
			free(tokens);
			return (NULL);
		}
		num_tokns++;
		token = strtok(NULL, " ");
	}

	tokens[num_tokns] = NULL;
	return (tokens);
}

void _perror(stack_t **stack, unsigned int L, char *s)
{
	fprintf(stderr, "L%d: %s\n", L, s);
	free_stack(stack);
	free_2d();
	if (info.monty_file)
		free(info.monty_file);
	exit(EXIT_FAILURE);
}
