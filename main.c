#include "monty.h"
struct info_s info = {"stack", 0};
/**
 * main - main function
 * @argv: arguments vector array
 * @argc: argv length
 * Return: 0 or other thing in faliure
*/
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char *trimmed;
	char buffer[8192], **splitted_line, *filename = argv[1];
	FILE *monty_file;
	void (*opcode)(stack_t **, unsigned int);

	if (argc != 2)
		errno_argc(&stack);
	monty_file = fopen(filename, "r");
	if (monty_file == NULL)
		errno_fd(filename, &stack);
	while (fgets(buffer, 8192, monty_file) != NULL)
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
				error_instruction(&stack, info.LINE, splitted_line[0], &splitted_line);
		}
		else
			opcode(&stack, info.LINE);
		free_2d(&splitted_line);
	}
	fclose(monty_file);
	free_2d(&splitted_line);
	free_stack(&stack);
	return (0);
}
