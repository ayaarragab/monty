#include "monty.h"

/**
 * rotl - rotates the stack to the top.
 * @stack: pointer to the top of the stack
 * @L: line number
 * Return: nothing
 */
void rotl(stack_t **stack, unsigned int L)
{
	stack_t *current = *stack, *top = *stack;

	(void)L;
	if ((*stack) == NULL || (*stack)->next == NULL)
		return;
	while (current->next != NULL)
		current = current->next;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	current->next = top;
	top->prev = current;
	top->next = NULL;
}
