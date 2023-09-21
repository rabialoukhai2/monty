#ifndef __MONTY_H__
#define __MONTY_H__
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/*OPCODE */
extern char **op_toks;

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
	struct stack_s *prev;
	struct stack_s *next;
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
	void (*f)(stack_t **stack, unsigned int value_ln);
}

instruction_t;

void stack_free(stack_t **stack);
int stack_init(stack_t **stack);
int mode_check(stack_t *stack);
void free_tokens(void);
unsigned int len_arrtoken(void);
int monty_runs(FILE *script_fd);

/*Opcode fun */
void push(stack_t **stack, unsigned int value_ln);
void pall(stack_t **stack, unsigned int value_ln);
void pint(stack_t **stack, unsigned int value_ln);
void pop(stack_t **stack, unsigned int value_ln);
void swap(stack_t **stack, unsigned int value_ln);
void add(stack_t **stack, unsigned int value_ln);
void nop(stack_t **stack, unsigned int value_ln);
void sub(stack_t **stack, unsigned int value_ln);
void div(stack_t **stack, unsigned int value_ln);
void mul(stack_t **stack, unsigned int value_ln);
void mod(stack_t **stack, unsigned int value_ln);
void pchar(stack_t **stack, unsigned int value_ln);
void pstr(stack_t **stack, unsigned int value_ln);
void rotl(stack_t **stack, unsigned int value_ln);
void rotr(stack_t **stack, unsigned int value_ln);
void stack(stack_t **stack, unsigned int value_ln);
void queue(stack_t **stack, unsigned int value_ln);

/*utils */
char **stow(char *str, char *delims);
char *get_int(int n);

/*Errors */
void set_optok_err(int error_code);
int short_stack_err(unsigned int value_ln, char *op);
int file_open_err(char *filename);
int malloc_err(void);
int msg_err(void);
int no_int_err(unsigned int value_ln);
int unknown_open_err(char *opcode, unsigned int value_ln);
int pint_err(unsigned int value_ln);
int div_err(unsigned int value_ln);
int pchar_err(unsigned int value_ln, char *message);
int pop_err(unsigned int value_ln);


#endif /*__MONTY_H__ */
