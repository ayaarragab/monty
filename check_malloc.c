#include "monty.h"
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
