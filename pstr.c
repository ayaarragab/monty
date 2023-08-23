#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to the top of the stack
 * @L: line number
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int L)
{
	stack_t *top = *stack;
	int n;

	(void)L;
	while (top != NULL)
	{
		n = top->n;
		if (n > 0 && n <= 127)
			putc((char)n, stdout);
		else
			break;
		top = top->next;
	}
	putc('\n', stdout);
}

