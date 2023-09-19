#include "monty.h"

/* Function to print all values on the stack */
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;
/* Check if the stack is empty */
if (current == NULL)
{
return;
}

/* Traverse the stack and print all values */
while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}
