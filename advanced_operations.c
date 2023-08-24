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
		_perror(stack, L, "can't pchar, stack empty");
	n = top->n;
	if (n < 0 || n > 127)
	{
		_perror(stack, L, "can't pchar, value out of range");
	}
	printf("%c\n", (char)n);
}
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
