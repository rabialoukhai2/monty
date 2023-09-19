#include "monty.h"

/**
 *push - Pushes an element onto the stack.
 *@stack: A pointer to the stack.
 *@line_number: The line number in the Monty bytecode file.
 *@value: The integer value to push onto the stack.
 *
 *Return: Nothing.
 */
void push(stack_t **stack, unsigned int line_number, int value)
{
	stack_t * new_node;

	if (!isdigit(value) && (value[0] != '-' && !isdigit(value[1])))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(value);
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
