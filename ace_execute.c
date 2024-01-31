#include "monty.h"

/**
* execute_f - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute_f(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", push_file}, {"pall", pall_file}, {"pint", pint_file},
				{"pop", pop_file}, {"swap", swap_file}, {"add", add_file},
				{"nop", nop_file, {"sub", sub_file}, {"div", div_file},
				{"mul", mul_file}, {"mod", mod_file}, {"pchar", pchar_file},
				{"pstr", pstr_file}, {"rotl", rotl_file}, {"rotr", rotr_file},
				{"queue", queue_file}, {"stack", stack_file},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		stack_free(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
