#define _GNU_SOURCE
#include "monty.h"
#include <string.h>
#include <stdio.h>

void release_tokens(void);
unsigned int get_token_len(void);
int checks_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int run_monty(FILE *script_fd);

/**
 * release_tokens - Frees the global op_toks array of strings.
 */
void release_tokens(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;

	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}

/**
 * get_token_len - Gets the length of current op_toks.
 *
 * Return: Length of current op_toks (as int).
 */
unsigned int get_token_len(void)
{
	unsigned int toks_len = 0;

	while (op_toks[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * checks_empty_line - Checks if a line read from getline only contains delim.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int checks_empty_line(char *line, char *delims)
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
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", push_monty},
		{"pall", pall_monty},
		{"pint", pint_monty},
		{"pop", pop_monty},
		{"swap", swap_monty},
		{"add", add_monty},
		{"nop", nop_monty},
		{"sub", sub_monty},
		{"div", div_monty},
		{"mul", mul_monty},
		{"mod", mod_monty},
		{"pchar", pchar_monty},
		{"pstr", pstr_monty},
		{"rotl", rotl_monty},
		{"rotr", rotr_monty},
		{"stack", stack_monty},
		{"queue", queue_monty},
		{NULL, NULL}
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
 * run_monty - Primary function to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int run_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_num = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (stack_init(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, script_fd) != 1)
	{
		line_num++;
		op_toks = strtow(line, DELIMS);
		if (op_toks == NULL)
		{
			if (checks_empty_line(line, DELIMS))
				continue;
			stack_free(&stack);
			return (print_malloc_error());
		}
		else if (op_toks[0][0] == '#') /* comment line */
		{
			release_tokens();
			continue;
		}
		op_func = get_op_func(op_toks[0]);
		if (op_func == NULL)
		{
			stack_free(&stack);
			exit_status = unknown_op_err(op_toks[0], line_num);
			release_tokens();
			break;
		}
		prev_tok_len = get_token_len();
		op_func(&stack, line_num);
		if (get_token_len() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				exit_status = atoi(op_toks[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			release_tokens();
			break;
		}
		release_tokens();
	}
	stack_free(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (print_malloc_error());
	}

	free(line);
	return (exit_status);
}
