#include "monty.h"
/**
 * add - implementation of monty add
 * @stack: pointer to top of the stack
 * @line_number: line_number
 * Return: nothing
*/
void add(stack_t **stack, unsigned int line_number)
{
	int add;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	add = (*stack)->n + (*stack)->next->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = add;
}
