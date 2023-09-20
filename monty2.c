#include "monty.h"

/**
 *main - Monty bytecode interpreter
 *@argc: The number of command-line arguments.
 *@argv: An array of command-line argument strings.
 *
 *Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		process_line(line, &stack, line_number);
	}

	free(line);
	fclose(file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
