#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_t
{
	int n;
	struct stack_t *prev;
	struct stack_t *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_num);
} instruction_t;

void stack_free(stack_t **stack);
int stack_init(stack_t **stack);
int check_stack_mode(stack_t *stack);
void release_tokens(void);
unsigned int get_token_len(void);
int run_monty(FILE *script_fd);
void set_tok_error(int error_code);

void push_monty(stack_t **stack, unsigned int line_num);
void pall_monty(stack_t **stack, unsigned int line_num);
void pint_monty(stack_t **stack, unsigned int line_num);
void pop_monty(stack_t **stack, unsigned int line_num);
void swap_monty(stack_t **stack, unsigned int line_num);
void add_monty(stack_t **stack, unsigned int line_num);
void nop_monty(stack_t **stack, unsigned int line_num);
void sub_monty(stack_t **stack, unsigned int line_num);
void div_monty(stack_t **stack, unsigned int line_num);
void mul_monty(stack_t **stack, unsigned int line_num);
void mod_monty(stack_t **stack, unsigned int line_num);
void pchar_monty(stack_t **stack, unsigned int line_num);
void pstr_monty(stack_t **stack, unsigned int line_num);
void rotl_monty(stack_t **stack, unsigned int line_num);
void rotr_monty(stack_t **stack, unsigned int line_num);
void stack_monty(stack_t **stack, unsigned int line_num);
void queue_monty(stack_t **stack, unsigned int line_num);

char **strtow(char *str, char *delims);
char *get_int(int n);


int use_error(void);
int print_malloc_error(void);
int file_open_error(char *filename);
int unknown_op_err(char *opcode, unsigned int line_num);
int no_int_err(unsigned int line_num);
int print_pop_error(unsigned int line_num);
int print_pint_error(unsigned int line_num);
int short_stack_err(unsigned int line_num, char *op);
int print_div_error(unsigned int line_num);
int print_pchar_error(unsigned int line_num, char *message);


#endif
