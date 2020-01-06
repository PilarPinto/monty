#include "monty.h"
/**
 * main - Is the main function
 * @argc:Is the index of argv
 * @argv:Is the array of arguments passed by
 * Return: 0 if is success
 */

int main(int argc, char **argv)
{
	FILE *file_handle;
	char *line_inf;
	size_t size = 0;
	ssize_t line_content = 1;
	stack_t *stack = NULL;
	unsigned int lnum = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_handle = fopen(argv[1], "r");
	aux.file = file_handle;

	if (file_handle == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (line_content > 0)
	{
		line_inf = NULL;
		line_content = getline(&line_inf, &size, file_handle);
		aux.line_inf = line_inf;
		line_number++;

		if (line_content > 0)
		{
			opcSelec(line_inf, &stack, lnum, file);
		}
		free(line_inf);
	}
	freePlates(stack);
	fclose(file);

return(0);
}


/**
 * freePlates
 * @stack: Pointer to stack mem address
 */
void freePlates(stack_t *stack)
{
	stack_t *plate;
	plate = stack;
	while(stack)
	{
		plate = stack->next;
		free(stack);
		stack = plate;
	}
}


/**
 * opcSelec - Selector of functions
 * @line_inf: Is the words in the line
 * @stack: Pointer to the stack mem add
 * @lnum: current liner number
 * @file: Is the monty file
 */
int opcSelec(char *line_inf, stack_t **stack, unsigned int lnum, FILE *file)
{
	unsigned int ind  = 0;
	char *codeOp;

	instruction_t listOpc[] = {
		{"push", push_data}, {"pall", print_stack}, {"pint", print_top},
		{"pop", delete_top}, {"swap", swap2top}, {"add", addm},
		{"nop", nop}, {"sub", subm}, {"div", divm}, {"mul", mulm},
		{"mod", modm}, {"pchar", printTopC}, {"pstr", printTopS},
		{"rotl", rotateTop}, {"rotr", rotateBottom}, {"queue", queuef},
		{"stack", stackf}, {NULL, NULL}
	};
	codeOp = strtok(line_inf, " \n\t");
	if(codeOp && listOpc[0] == "#")
		return (0);

	aux.val = strtok(NULL, " \n\t");

	while (listOpc[ind].opcode && codeOp)
	{
		if (strcmp(codeOp, listOpc[ind].opcode) == 0)
		{
			listOpc[ind].f(stack, lnum);
			return (0);
		}
		i++;
	}
	if (codeOp && listOpc[ind].opcode == NULL)
	{
		fpritnf(stderr, "L%d: unknown instruction %s\n", lnum, codeOp);
		fclose(file);
		free(line_inf);
		free_nodes(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);

}
