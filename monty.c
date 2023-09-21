#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 *main - Entry point for the Monty interpreter
 *
 *@argc: Number of command-line arguments
 *@argv: Array of pointers to command-line argument strings
 *
 *Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int main(int argc, char **argv)
{
	/**
	 *script_fd - File pointer for the Monty script
	 */
	FILE *script_fd = NULL;

	/**
	 *exit_code - Exit code to be returned
	 */
	int exit_code = EXIT_SUCCESS;

	/*Check the number of command-line arguments */
	if (argc != 2)
		return (msg_err());

	/*Attempt to open the script file */
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (file_open_err(argv[1]));

	/*Run the Monty interpreter */
	exit_code = monty_runs(script_fd);

	/*Close the script file */
	fclose(script_fd);

	return (exit_code);
}
