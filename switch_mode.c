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
	info.mode = "stack";
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
	info.mode = "queue";
}
