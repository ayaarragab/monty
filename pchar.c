#include "monty.h"

/**
 * pchar - print a character
 * @stack: pointer to top of the stack
 * @L: line number
 * Return: nothing
 */
void pchar(stack_t **stack, unsigned int L)
{
	stack_t *top = *stack;
	int n;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", L);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	n = top->n;
	if (n < 0 || n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", L);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)n);
}
