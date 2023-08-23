#include "monty.h"
/**
 * mod - implementation of monty mod
 * @stack: pointer to top of the stack
 * @line_number: line_number
 * Return: nothing
*/
void mod(stack_t **stack, unsigned int line_number)
{
	int mod;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	mod = (*stack)->next->n % (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = mod;
}
