#include "monty.h"

/**
 *swap - Swaps the top two elements of the stack.
 *@stack: A pointer to the stack.
 *@line_number: The line number in the Monty bytecode file.
 *
 *Return: Nothing.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *current = *stack;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/*Swap the values of the top two elements */
	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}
