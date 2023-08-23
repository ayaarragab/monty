#include "monty.h"
/**
 * mul - implementation of monty mul
 * @stack: pointer to top of the stack
 * @line_number: line_number
 * Return: nothing
*/
void mul(stack_t **stack, unsigned int line_number)
{
	int mul;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	mul = (*stack)->n * (*stack)->next->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = mul;
}
