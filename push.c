#include "monty.h"

/* Function to push an element onto the stack */
void
push (stack_t ** stack, unsigned int line_number, int value)
{
  stack_t *new_node;

  /* Check if the value is an integer */
  if (!isdigit (value) && (value[0] != '-' && !isdigit (value[1])))
    {
      fprintf (stderr, "L%u: usage: push integer\n", line_number);
      exit (EXIT_FAILURE);
    }

  /* Allocate memory for a new node */
  new_node = malloc (sizeof (stack_t));
  if (new_node == NULL)
    {
      fprintf (stderr, "Error: malloc failed\n");
      exit (EXIT_FAILURE);
    }

  /* Set the value of the new node */
  new_node->n = atoi (value);

  /* Connect the new node to the stack */
  new_node->next = *stack;
  new_node->prev = NULL;

  if (*stack != NULL)
    {
      (*stack)->prev = new_node;
    }

  /* Update the stack pointer */
  *stack = new_node;
}
