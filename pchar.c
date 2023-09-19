nclude "monty.h"

/**
 *  *pchar_op - Prints the char at the top of the stack.
 *   *@stack: A pointer to the stack.
 *    *@line_number: The line number in the Monty bytecode file.
 *     *
 *      *Return: Nothing.
 *       */
void pchar_op(stack_t **stack, unsigned int line_number)
{
		stack_t *current = *stack;

			if (current == NULL)
					{
								fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
										exit(EXIT_FAILURE);
											}

				if (!isascii(current->n))
						{
									fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
											exit(EXIT_FAILURE);
												}

					putchar(current->n);
						putchar('\n');
}
