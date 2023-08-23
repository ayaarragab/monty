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
	fflush(NULL);
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
		free_stack(stack);
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
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(stack);
		free_2d(&info.splitted_line);
		exit(EXIT_FAILURE);
	}
	second = (*stack)->next;
	second->prev = NULL;
	if (second->next)
	{
		second->next->prev = (*stack);
		(*stack)->next = second->next;
	}
	else
		(*stack)->next = NULL;
	second->next = (*stack);
	second->prev = NULL;
	(*stack) = second;
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
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
		return;
	}
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
