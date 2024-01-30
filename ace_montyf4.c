#include "monty.h"

void rotl_monty(stack_t **stack, unsigned int line_num);
void rotr_monty(stack_t **stack, unsigned int line_num);
void stack_monty(stack_t **stack, unsigned int line_num);
void queue_monty(stack_t **stack, unsigned int line_num);

/**
 * rotl_monty - Rotates the top value of a stack_t linked list to the bottom.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */
void rotl_monty(stack_t **stack, unsigned int line_num)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_num;
}

/**
 * rotr_monty - Rotates the bottom value of a stack_t linked list to the top.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */
void rotr_monty(stack_t **stack, unsigned int line_num)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_num;
}

/**
 * stack_monty - Converts a queue to a stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */
void stack_monty(stack_t **stack, unsigned int line_num)
{
	(*stack)->n = STACK;
	(void)line_num;
}

/**
 * queue_monty - Converts a stack to a queue.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */
void queue_monty(stack_t **stack, unsigned int line_num)
{
	(*stack)->n = QUEUE;
	(void)line_num;
}
