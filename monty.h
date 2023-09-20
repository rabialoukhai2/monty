#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>

/**
 *struct stack_s - doubly linked list representation of a stack (or queue)
 *@n: integer
 *@prev: points to the previous element of the stack (or queue)
 *@next: points to the next element of the stack (or queue)
 *
 *Description: doubly linked list node structure
 *for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s * prev;
	struct stack_s * next;
}

stack_t;

/**
 *struct instruction_s - opcode and its function
 *@opcode: the opcode
 *@f: function to handle the opcode
 *
 *Description: opcode and its function
 *for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void(*f)(stack_t **stack, unsigned int line_number);
}

instruction_t;

/*Global variables */
struct
{
	int data_struct; /*Data structure selector (stack/queue) */
	char *argument; /*Argument for opcode functions */
}

global;

/*Function prototypes for opcode handlers */
void push(stack_t **stack, int value);
void add(stack_t **stack, unsigned int line_number);
void div_op(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/*Function prototypes for utility functions */
void error_usage(void);
void file_error(char *argv);
void free_stack(stack_t *stack);
void opcode(stack_t **stack, char *str, unsigned int line_cnt);


#endif /*MONTY_H */
