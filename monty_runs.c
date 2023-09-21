#define _GNU_SOURCE
#include "monty.h"
#include <string.h>



void free_tokens(void);
unsigned int len_arrtoken(void);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t **, unsigned int);
int monty_runs(FILE *script_fd);

/**
 * free_tokens - Frees the global op_toks array of strings.
 */
void free_tokens(void)
{
    	size_t i = 0;

	if (op_toks == NULL)
		return;

	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}

/**
 * len_arrtoken - Gets the length of current op_toks.
 *
 * Return: Length of current op_toks (as int).
 */
unsigned int len_arrtoken(void)
{
    	unsigned int toks_len = 0;

	while (op_toks[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * is_empty_line - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int is_empty_line(char *line, char *delims)
{
    	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}

		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * get_op_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*get_op_func(char *opcode))(stack_t **, unsigned int)
{
	instruction_t op_funcs[] = {
		{ "push", push
		},
		{ "pall", pall
		},
		{ "pint", pint
		},
		{ "pop", pop
		},
		{ "swap", swap
		},
		{ "add", add
		},
		{ "nop", nop
		},
		{ "sub", sub
		},
		{ "div", div
		},
		{ "mul", mul
		},
		{ "mod", mod
		},
		{ "pchar", pchar
		},
		{ "pstr", pstr
		},
		{ "rotl", rotl
		},
		{ "rotr", rotr
		},
		{ "stack", stack
		},
		{ "queue", queue
		},
		{
			NULL, NULL
		}
	};

	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

/**
 * monty_runs - Primary function to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int monty_runs(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int value_ln = 0, prev_tok_len = 0;
	void(*op_func)(stack_t **, unsigned int);

	if (stack_init(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, script_fd) != -1)
	{
		value_ln++;
		op_toks = stow(line, DELIMS);
		if (op_toks == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			stack_free(&stack);
			return (malloc_err());
		}
		else if (op_toks[0][0] == '#') /*comment line */
		{
			free_tokens();
			continue;
		}

		op_func = get_op_func(op_toks[0]);
		if (op_func == NULL)
		{
			stack_free(&stack);
			exit_status = unknown_open_err(op_toks[0], value_ln);
			free_tokens();
			break;
		}

		prev_tok_len = len_arrtoken();
		op_func(&stack, value_ln);
		if (len_arrtoken() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				exit_status = atoi(op_toks[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_tokens();
			break;
		}

		free_tokens();
	}

	stack_free(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (malloc_err());
	}

	free(line);
	return (exit_status);
}
