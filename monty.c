#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
char **op_toks = NULL;
/**
 *main - Entry point for the Monty interpreter
 *@argc: Number of command-line arguments
 *@argv: Array of pointers to command-line argument strings
 *
 *Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int main(int argc, char **argv)
{

	FILE *script_fd = NULL;

	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (msg_err());

	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (file_open_err(argv[1]));

	exit_code = monty_runs(script_fd);

	fclose(script_fd);

	return (exit_code);
}
