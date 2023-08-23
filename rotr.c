#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to the top of the stack
 * @L: line number
 * Return: nothing
 */
void rotr(stack_t **stack, unsigned int L)
{
	stack_t *current = *stack, *top = *stack;

	(void)L;
	if ((*stack) == NULL || (*stack)->next == NULL)
		return;
	while (current->next != NULL)
		current = current->next;
	current->prev->next = NULL;
	current->prev = NULL;
	current->next = top;
	top->prev = current;
	(*stack) = current;
}
