#include "monty.h"
/**
 * add - implementation of monty add
 * @stack: pointer to top of the stack
 * @line_number: line_number
 * Return: nothing
*/
void add(stack_t **stack, unsigned int line_number)
{
	int add;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	add = (*stack)->n + (*stack)->next->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = add;
}
/**
 * sub - implementation of monty sub
 * @stack: pointer to top of the stack
 * @line_number: line_number
 * Return: nothing
*/
void sub(stack_t **stack, unsigned int line_number)
{
	int sub;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->next->n - (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = sub;
}
/**
 * mul - implementation of monty mul
 * @stack: pointer to top of the stack
 * @line_number: line_number
 * Return: nothing
*/
void mul(stack_t **stack, unsigned int line_number)
{
	int mul;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	mul = (*stack)->n * (*stack)->next->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = mul;
}
/**
 * divi - implementation of monty division
 * @stack: pointer to top of the stack
 * @line_number: line_number
 * Return: nothing
*/
void divi(stack_t **stack, unsigned int line_number)
{
	int div;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	div = (*stack)->next->n / (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = div;
}
/**
 * mod - implementation of monty mod
 * @stack: pointer to top of the stack
 * @line_number: line_number
 * Return: nothing
*/
void mod(stack_t **stack, unsigned int line_number)
{
	int mod;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	mod = (*stack)->next->n % (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = mod;
}
