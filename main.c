#include "monty.h"
struct info_s info = {"stack", NULL, NULL, 0};
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
	char buffer[8192], *filename = argv[1];
	void (*opcode)(stack_t **, unsigned int);

	if (argc != 2)
		errno_argc(&stack);
	info.monty_file = fopen(filename, "r");
	if (info.monty_file == NULL)
		errno_fd(filename, &stack);
	while (fgets(buffer, 8192, info.monty_file) != NULL)
	{
		info.LINE++;
		if (buffer[0] == '\n' || !check_if_all_spaces(buffer) || is_comment(buffer))
			continue;
		trimmed = trim(buffer);
		info.splitted_line = make_array_of_strings(trimmed);
		opcode = is_opcode(strtok(info.splitted_line[0], "\n"));
		if (opcode == NULL)
		{
			if (strcmp(info.splitted_line[0], "push") == 0)
				call_push(&stack, info.LINE, info.splitted_line[1]);
			else
				error_instruction(&stack, info.LINE, info.splitted_line[0]);
		}
		else
			opcode(&stack, info.LINE);
		free_2d();
	}
	fclose(info.monty_file);
	free_2d();
	free_stack(&stack);
	return (0);
}
