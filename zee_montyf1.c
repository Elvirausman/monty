#include "monty.h"

void push_monty(stack_t **stack, unsigned int line_num);
void pall_monty(stack_t **stack, unsigned int line_num);
void pint_monty(stack_t **stack, unsigned int line_num);
void pop_monty(stack_t **stack, unsigned int line_num);
void swap_monty(stack_t **stack, unsigned int line_num);

/**
 * push_monty - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */
void push_monty(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_tok_error(print_malloc_error());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_tok_error(no_int_err(line_num));
		return;
	}

	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			set_tok_error(no_int_err(line_num));
			return;
		}
	}
	new->n = atoi(op_toks[1]);

	if (check_stack_mode(*stack) == STACK) /* STACK mode insert at front */
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else /* QUEUE mode insert at end */
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}

/**
 * pall_monty - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */
void pall_monty(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_num;
}

/**
 * pint_monty - Prints the top value of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */
void pint_monty(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL)
	{
		set_tok_error(print_pint_error(line_num));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}


/**
 * pop_monty - Removes the top value element of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */
void pop_monty(stack_t **stack, unsigned int line_num)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_tok_error(print_pop_error(line_num));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * swap_monty - Swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */
void swap_monty(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_tok_error(short_stack_err(line_num, "swap"));
		return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
