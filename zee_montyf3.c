#include "monty.h"

void nop_monty(stack_t **stack, unsigned int line_num);
void pchar_monty(stack_t **stack, unsigned int line_num);
void pstr_monty(stack_t **stack, unsigned int line_num);

/**
 * nop_monty - Does absolutely nothing for the Monty opcode 'nop'.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */
void nop_monty(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}

/**
 * pchar_monty - Prints the character in the top value
 *               node of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */
void pchar_monty(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL)
	{
		set_tok_error(print_pchar_error(line_num, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_tok_error(print_pchar_error(line_num,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * pstr_monty - Prints the string contained in a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */
void pstr_monty(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)line_num;
}
