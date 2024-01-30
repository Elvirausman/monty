#include "monty.h"

void add_monty(stack_t **stack, unsigned int line_num);
void sub_monty(stack_t **stack, unsigned int line_num);
void div_monty(stack_t **stack, unsigned int line_num);
void mul_monty(stack_t **stack, unsigned int line_num);
void mod_monty(stack_t **stack, unsigned int line_num);

/**
 * add_monty - Adds the top two values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void add_monty(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_tok_error(short_stack_err(line_num, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	pop_monty(stack, line_num);
}

/**
 * sub_monty - Subtracts the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void sub_monty(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_tok_error(short_stack_err(line_num, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	pop_monty(stack, line_num);
}

/**
 * div_monty - Divides the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void div_monty(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_tok_error(short_stack_err(line_num, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_tok_error(print_div_error(line_num));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	pop_monty(stack, line_num);
}

/**
 * mul_monty - Multiplies the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void mul_monty(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_tok_error(short_stack_err(line_num, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	pop_monty(stack, line_num);
}

/**
 * mod_monty - Computes the modulus of the second value from the
 *             top of a stack_t linked list  by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void mod_monty(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_tok_error(short_stack_err(line_num, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_tok_error(print_div_error(line_num));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	pop_monty(stack, line_num);
}
