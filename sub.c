#include "monty.h"

/**
 * sub - implementation of monty sub
 * @stack: pointer to top of the stack
 * @line_number: line_number
 * Return: nothing
*/
void sub(stack_t **stack, unsigned int line_number)
{
	int sub;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->next->n - (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = sub;
}
