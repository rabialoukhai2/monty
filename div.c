#include "monty.h"

/**
 *div_op - Divides the second top element by the top element of the stack.
 *@stack: A pointer to the stack.
 *@line_number: The line number in the Monty bytecode file.
 *
 *Return: Nothing.
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (current->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	current->next->n /= current->n;
	pop(stack, line_number);
}
