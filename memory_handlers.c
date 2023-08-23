#include "monty.h"
/**
 * free_stack - frees a doubly linked list
 * @head: head
 * Return: nothing
*/
void free_stack(stack_t **head)
{
	stack_t *current = *head;

	if (*head == NULL)
		return;

	while (current->next)
	{
		current = current->next;
		free(current->prev);
		current->prev = NULL;
	}
	free(current);
	current = NULL;
}
/**
 * free_2d - frees a 2d array
 * @arr_2D: 2d arr
 * Return: nothing
*/
void free_2d(char ***arr_2D)
{
	int i;

	if (*arr_2D == NULL)
		return;
	for (i = 0; (*arr_2D)[i] != NULL; i++)
	{
		free((*arr_2D)[i]);
		(*arr_2D)[i] = NULL;
	}
	free(*arr_2D);
	*arr_2D = NULL;
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
