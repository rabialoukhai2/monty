#include "monty.h"

/**
 *pall - Prints all the elements in the stack or queue.
 *@stack: A pointer to the stack or queue.
 *@value_ln: The line number (unused in this function).
 *
 *Description: This function prints all the elements in the stack or queue.
 *It starts from the top of the stack (or front of the queue) and iterates
 *through the elements, printing each one.
 */

void pall(stack_t **stack, unsigned int value_ln)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}

	(void) value_ln;
}
