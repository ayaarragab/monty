#include "monty.h"
/**
 * divi - implementation of monty division
 * @stack: pointer to top of the stack
 * @line_number: line_number
 * Return: nothing
*/
void divi(stack_t **stack, unsigned int line_number)
{
	int div;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	div = (*stack)->next->n / (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = div;
}
