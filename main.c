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

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_handle = fopen(argv[1], "r");
	
	if (file_handle == NULL)
	{	
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	return(0);
}
