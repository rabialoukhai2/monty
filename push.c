#include "monty.h"

void push(stack_t **stack, unsigned int value_ln);

/**
 *push - Pushes a new element onto the stack or queue.
 *@stack: A pointer to the stack or queue.
 *@value_ln: The line number of the value to be pushed.
 *
 *Description: This function pushes a new element onto the stack or queue
 *depending on the current mode (STACK or QUEUE). It checks if the value is
 *a valid integer and performs the necessary operations to insert it.
 */
void push(stack_t **stack, unsigned int value_ln)
{
	stack_t *tmp, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_optok_err(malloc_err());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_optok_err(no_int_err(value_ln));
		return;
	}

	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i]<'0' || op_toks[1][i] > '9')
		{
			set_optok_err(no_int_err(value_ln));
			return;
		}
	}

	new->n = atoi(op_toks[1]);

	if (mode_check(*stack) == STACK)
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}
