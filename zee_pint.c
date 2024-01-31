#include "monty.h"

/**
 * pint_file - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void pint_file(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
