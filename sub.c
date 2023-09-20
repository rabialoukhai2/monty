#include "monty.h"

/**
 *sub - Subtracts the top element from the second top element of the stack.
 *@stack: A pointer to the stack.
 *@line_number: The line number in the Monty bytecode file.
 *
 *Return: Nothing.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	current->next->n -= current->n;
	pop(stack, line_number);
}
