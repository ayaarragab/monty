#include "monty.h"
/**
 * swap - implementation of monty swap
 * @stack: pointer to top of the stack
 * @line_number: line_number
 * Return: nothing
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *ref_to_head = *stack, *next_node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	next_node = (*stack)->next;
	(*stack)->prev = NULL;
	(*stack)->next = ref_to_head;
	ref_to_head->prev = (*stack);
	ref_to_head->next = next_node;
}
