#include "monty.h"
struct info_s info = {"stack", 0};
/**
 * error_instruction - when an unknown instruction
 * @stack: stack
 * @line: line_number
 * @instr: instruction
 * @buf: buffer
 * Return: nothing
*/
void error_instruction(stack_t *stack, int line, char *instr, char **buf)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line, instr);
	free_2d(buf);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
/**
 * errno_argc - argc error
 * @stack: stack
 * Return: nothing
*/
void errno_argc(stack_t *stack)
{
	fprintf(stderr, "USAGE: monty file\n");
	free_stack(stack);
	exit(EXIT_FAILURE);
}
/**
 * errno_fd - fd error
 * @str: filename
 * @stack: stack
 * Return: nothing
*/
void errno_fd(char *str, stack_t *stack)
{
	fprintf(stderr, "Error: Can't open file %s\n", str);
	free_stack(stack);
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
/**
 * main - main function
 * @argv: arguments vector array
 * @argc: argv length
 * Return: 0 or other thing in faliure
*/
int main(int argc, char **argv)
{
	stack_t *stack = malloc(sizeof(stack_t));
	char *trimmed;
	char buffer[BUFSIZ], **splitted_line, *filename = argv[1];
	FILE *monty_file;
	void (*opcode)(stack_t **, unsigned int);

	check_malloc(stack);
	stack = NULL;
	if (argc != 2)
		errno_argc(stack);
	check_malloc2(buffer);
	monty_file = fopen(argv[1], "r");
	if (monty_file == NULL)
		errno_fd(filename, stack);
	while (fgets(buffer, BUFSIZ, monty_file) != NULL)
	{
		info.LINE++;
		if (buffer[0] == '\n' || !check_if_all_spaces(buffer) || is_comment(buffer))
			continue;
		trimmed = trim(buffer);
		splitted_line = make_array_of_strings(trimmed);
		opcode = is_opcode(strtok(splitted_line[0], "\n"));
		if (opcode == NULL)
		{
			if (strcmp(splitted_line[0], "push") == 0)
				call_push(&stack, info.LINE, splitted_line[1]);
			else
				error_instruction(stack, info.LINE, splitted_line[0], splitted_line);
		}
		else
			opcode(&stack, info.LINE);
	}
	fclose(monty_file);
	free_2d(splitted_line);
	free_stack(stack);
	return (0);
}
