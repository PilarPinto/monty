#include "monty.h"
/**
 * push_data - Add new data to stack
 * @stack. Is the pointer to the stack mem address
 * @l: Is the current line number
 */
void push_data(stack_t **stack, unsigned int l)
{

	int node, i = 0;

	if (aux.val != NULL)
	{
		if (aux.val[0] == '-')
			i++;
		for (; aux.val[i] != '\0', i++)
		{
			if (isdigit(aux.val[i]) == 0)
			{
			       fprintf(stderr, "L%d: usage: push integer\n", l);
			       fclose(aux.file);
			       free(aux.line_inf);
			       freePlates(*stack);
			       exit(EXIT_FAILURE);			}
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", l);
		fclose(aux.file);
		free(aux.line_inf);
		freePlates(*stack);
		exit(EXIT_FAILURE);
	}

	push_data = atoi(aux.val);
	if (aux.flag_sq == 0)
		add_top(stack, push_data);
	else
		add_last(atack, push_data);
}

/**
 * add_top - Adding a element to head
 * @stack: Is the pointer to the stack mem address
 * @push_data: Is the data argument of the push
 */
void add_top(stack_t **stack, int push_data)
{
	stack_t *front = *stack;
       	stack_t *new_plate = malloc(sizeof(stack_t));

	if (new_plate == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (tmp != NULL)
		tmp->prev = new_plate;
	new_plate->n = push_data;
	new_plate->next = *stack;
	new_plate->prev = NULL;
	*stack = new_plate

}

/**
 * add_last - Adds a element to the tail
 * @stack: Is the pointer to the stack
 * @push_data: Is the data with the push
 */
void add_last(stack_t **stack, int push_data)
{
	stack_t *new_plate = malloc(sizeof(stack_t));
	stack_t *last = *stack;

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
 * delete_top - Delete the top element
 * @stack: Is the pointer to the stack mem address
 * @line_number:Is the current line number
 */
void delete_top(stack_t **stack, unsigned int line_number)
{
	stack_t *rem_plate;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(aux.file);
		free(aux.line_inf);
		freePlates(*stack);
		exit(EXIT_FAILURE);
	}
	rem_plate = *stack;
	*stack = rem_plate->next;
	free(rem_plate);
}


/**
 * nop - Don't do anything
 * @stack: Pointer to the stack mem address
 * @line_number: Is the current line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
