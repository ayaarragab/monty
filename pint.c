#include "monty.h"
/**
 * pint - implementation of monty pint
 * @stack: pointer to top of the stack
 * @line_number: line_number
 * Return: nothing
*/
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", current->n);
}
