#include "monty.h"
/**
 * push_data - Add new data to stack
 *
 *
 */
void push_data(stack_t **stack, unsigned int line_number, int push_data)
{
	stack_t *new_plate = malloc(sizeof(stack_t));
	stack_t *last = *stack;
	(void)line_number;

	new_plate->n = push_data;

	new_plate->next = NULL;

	if (*stack == NULL)
	{
		new_plate->prev = NULL;
		*stack = new_plate;
		return;
	}
	while (last->next != NULL)
		last = last->next;

	last->next = new_plate;

	new_plate->prev = last;
}


/**
 *
 *
 *
 */
/* void delete_top(stack_t **stack, unsigned int line_number) */
/* {  */
/* 	stack_t *new_plate = malloc(sizeof(stack_t)); */
/* 	stack_t *last = *stack; */
/* } */


/**
 * nop - Don't do anything
 * @stack: 
 *
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
