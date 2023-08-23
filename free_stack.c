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
