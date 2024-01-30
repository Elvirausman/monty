#include "monty.h"

int use_error(void);
int print_malloc_error(void);
int file_open_error(char *filename);
int unknown_op_err(char *opcode, unsigned int line_num);
int no_int_err(unsigned int line_num);

/**
 * use_error - Prints usage error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int use_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * print_malloc_error - Prints malloc error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int print_malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * file_open_error - Prints file opening error messages w/ file name.
 * @filename: Name of file failed to open
 *
 * Return: (EXIT_FAILURE) always.
 */
int file_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_err - Prints unknown instruction error messages.
 * @opcode: Opcode where error occurred.
 * @line_num: Line number in Monty bytecodes file where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int unknown_op_err(char *opcode, unsigned int line_num)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_num, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_err - Prints invalid monty_push argument error messages.
 * @line_num: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int no_int_err(unsigned int line_num)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_num);
	return (EXIT_FAILURE);
}
