#include "monty.h"

/**
 *pall - Prints all the values on the stack.
 *@stack: Pointer to the stack.
 */
void pall(stack_t **stack)
{
	stack_t *temp = *stack;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
