#include "monty.h"
/**
 * print_stack - Print the stack like pall function
 * @stack: Pointer to the mem direction of stack
 * @line_number: Number of actual line
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *show_node = NULL;

	(void)line_number;

	if (!(stack == NULL || *stack == NULL))
	{
		show_node = *stack;
		while(show_node)
		{
			printf("%d\n", show_node->n);
			show_node = show_node->next;
		}
	}
}


/**
 * print_top - print the top element (pint)
 * @stack: Pointer to the mem direction of stack
 * @line_number: Number of actual line
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	stack_t *next_plate = NULL;
	if(stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint\n", line_number);
		exit(EXIT_FAILURE);
	}

	next_plate = (*stack)->next;
	while(next_plate != NULL)
	{
		next_plate = (*stack)->next;
	}
	printf("%d\n", next_plate->n);
}
