#include "monty.h"
/**
 * free_stack - frees a doubly linked list
 * @head: head
 * Return: nothing
*/
void free_stack(stack_t *head)
{
	stack_t *current = head, *nextnode = NULL;

	while (current != NULL)
	{
		nextnode = current->next;
		if (current->prev)
			current->prev->next = nextnode;
		if (nextnode)
			nextnode->prev = current->prev;
		free(current);
		current = nextnode;
	}
}
/**
 * free_2d - frees a 2d array
 * @arr_2D: 2d arr
 * Return: nothing
*/
void free_2d(char **arr_2D)
{
	int i;

	for (i = 0; arr_2D[i] != NULL; i++)
		free(arr_2D[i]);
	free(arr_2D);
}
/**
 * check_malloc2 - prints to stderr and exit by EXIT_FAILURE if malloc failed
 * @str: space that doesn't allocated
 * Return: nothing
*/
void check_malloc2(char *str)
{
	if (str == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}
/**
 * check_malloc - prints to stderr and exit by EXIT_FAILURE if malloc failed
 * @stack: space that doesn't allocated
 * Return: nothing
*/
void check_malloc(stack_t *stack)
{
	if (stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}
