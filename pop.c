#include "monty.h"
/**
 * pop - implementation of monty pop
 * @stack: pointer to top of the stack
 * @line_number: line_number
 * Return: nothing
*/
void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		free((*stack));
		*stack = NULL;
		return;
	}
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
