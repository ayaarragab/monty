#include "monty.h"

/**
 * stack - switch mode to LIFO
 * @stack: pointer to the front of the queue
 * @L: line number
 * Return: nothing
 */
void stack(stack_t **stack, unsigned int L)
{
	(void)stack;
	(void)L;
}

/**
 * queue - switch mode to FIFO
 * @stack: pointer to the top of the stack
 * @L: line number
 * Return: nothing
 */
void queue(stack_t **stack, unsigned int L)
{
	(void)stack;
	(void)L;
}

/**
 * switch_mode - switch mode
 * @stack: pointer to the top of the stack
 * @L: line number
 * @mode: current mode
 * Return: new mode
 */
char *switch_mode(stack_t **s, unsigned int L, char *mode)
{
	if (strcmp(mode, "stack") == 0)
	{
		stack(s, L);
		return ("stack");
	}
	else
	{
		queue(s, L);
		return ("queue");
	}
}
