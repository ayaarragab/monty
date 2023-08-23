#include "monty.h"
/**
 * pall - implementation of monty pall
 * @stack: pointer to top of the stack
 * @line_number: line_number
 * Return: nothing
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
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
/**
 * nop - implementation of monty nop
 * @stack: pointer to top of the stack
 * @line_number: line_number
 * Return: nothing
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void) stack;
}
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