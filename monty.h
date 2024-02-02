#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;
struct bus_s bus;

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
char *mem_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *line_is_clean(char *content);
void push_file(stack_t **head, unsigned int number);
void pall_file(stack_t **head, unsigned int number);
void pint_file(stack_t **head, unsigned int number);
int execute_f(char *content, stack_t **head, unsigned int counter, FILE *file);
void stack_free(stack_t *head);
void pop_file(stack_t **head, unsigned int counter);
void swap_file(stack_t **head, unsigned int counter);
void add_file(stack_t **head, unsigned int counter);
void nop_file(stack_t **head, unsigned int counter);
void sub_file(stack_t **head, unsigned int counter);
void div_file(stack_t **head, unsigned int counter);
void mul_file(stack_t **head, unsigned int counter);
void mod_file(stack_t **head, unsigned int counter);
void pchar_file(stack_t **head, unsigned int counter);
void pstr_file(stack_t **head, unsigned int counter);
void rotl_file(stack_t **head, unsigned int counter);
void rotr_file(stack_t **head, __attribute__((unused)) unsigned int counter);
void add_node(stack_t **head, int n);
void add_queue(stack_t **head, int n);
void queue_file(stack_t **head, unsigned int counter);
void stack_file(stack_t **head, unsigned int counter);

#endif
