#include "monty.h"
/**
 * main - main function
 * @argv: arguments vector array
 * @argc: argv length
 * Return: 0 or other thing in faliure
*/
int main(int argc, char **argv)
{
	stack_t *stack = malloc(sizeof(stack_t));
	char *trimmed, *mode = "stack";
	char buffer[BUFSIZ], **splitted_line, *filename = argv[1];
	FILE *monty_file;
	void (*opcode)(stack_t **, unsigned int);
	int LINE = 0;

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
		LINE++;
		if (buffer[0] == '\n' || !check_if_all_spaces(buffer) || is_comment(buffer))
			continue;
		trimmed = trim(buffer);
		splitted_line = make_array_of_strings(trimmed);
		opcode = is_opcode(strtok(splitted_line[0], "\n"));
		if (opcode == NULL)
		{
			if (strcmp(splitted_line[0], "push") == 0)
				call_push(&stack, LINE, splitted_line[1], mode);
			else if (strcmp(splitted_line[0], "stack") == 0 || strcmp(splitted_line[0], "queue") == 0)
				mode = switch_mode(&stack, LINE, splitted_line[0]);
			else
				error_instruction(stack, LINE, splitted_line[0], splitted_line);
		}
		else
			opcode(&stack, LINE);
	}
	fclose(monty_file);
	free_2d(splitted_line);
	free_stack(stack);
	return (0);
}
