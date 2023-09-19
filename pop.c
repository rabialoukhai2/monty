#include "monty.h"

/**
 *pop - Removes the top element from the stack.
 *@stack: A pointer to the stack.
 *@line_number: The line number in the Monty bytecode file.
 *
 *Return: Nothing.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t * temp;

	/*Check if the stack is empty */
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	/*Store the address of the top element in temp */
	temp = *stack;

	/*Update the stack pointer to point to the next element */
	*stack = (*stack)->next;

	/*Free the memory of the removed element */
	free(temp);
}
