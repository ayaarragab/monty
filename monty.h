#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
#define _POSIX_C_SOURCE 200809L

/**
 * struct info_s - struct holdes info about the program
 * @mode: program mode (stack, queue)
 * @LINE: line number
 * @monty_file: monty file
 * @splitted_line: line containing command
 *
 * Description: mode and line number
 */
struct info_s
{
	char *mode;
	char **splitted_line;
	FILE *monty_file;
	int LINE;
};
extern struct info_s info;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
void push(stack_t **stack, unsigned int line_number);
void call_push(stack_t **, unsigned int line_number, char *);
void check_malloc(stack_t *stack);
void pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **head);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void free_2d(void);
char *trim(char *command);
int check_if_all_spaces(char *command);
int is_comment(char *line);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void (*is_opcode(char *))(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);
void stack(stack_t **, unsigned int);
void queue(stack_t **, unsigned int);
int isnum(char *);
void divi(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void error_instruction(stack_t **stack, int line, char *instr);
void errno_argc(stack_t **stack);
void errno_fd(char *str, stack_t **stack);
char **make_array_of_strings(char *command);
void _perror(stack_t **, unsigned int, char *);
#endif /* MONTY_H */
