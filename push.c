#include "monty.h"
/**
 * push - implementation of monty push
 * @stack: pointer to top of the stack
 * @line_number: line_number
 * Return: nothing
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *pushed_node;

	(void)line_number;
	pushed_node = malloc(sizeof(stack_t));
	check_malloc(pushed_node);
	pushed_node->n = 0;
	pushed_node->next = NULL;
	pushed_node->prev = NULL;
	if (*stack != NULL)
	{
		pushed_node->next = *stack;
		(*stack)->prev = pushed_node;
	}
	*stack = pushed_node;
}

/**
 * push_q - push in queue
 * @stack: pointer to the front
 * @L: line number
 * Return: nothing
 */
void push_q(stack_t **stack, unsigned int L)
{
	stack_t *pushed_node, *current = (*stack);

	(void)L;
	pushed_node = malloc(sizeof(stack_t));
	check_malloc(pushed_node);
	pushed_node->n = 0;
	pushed_node->next = NULL;
	pushed_node->prev = NULL;
	if ((*stack) == NULL)
		*stack = pushed_node;
	else
	{
		while (current->next)
			current = current->next;
		current->next = pushed_node;
		pushed_node->prev = current;
	}
}

/**
 * call_push - helper function to call push
 * @stack: pointer to the first node
 * @L: line number
 * @num: number to push
 * Return: nothing
 */
void call_push(stack_t **stack, unsigned int L, char *num)
{
	stack_t *current = *stack;
	int number;

	if (isnum(num) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", L);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	number = atoi(num);
	if (strcmp(info.mode, "stack") == 0)
	{
		push(stack, L);
		(*stack)->n = number;
	}
	else
	{
		push_q(stack, L);
		if (current)
		{
			while (current->next)
				current = current->next;
			current->n = number;
		}
		else
			(*stack)->n = number;
	}
}
