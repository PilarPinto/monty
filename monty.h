#ifndef _MONTY_H_
#define _MONTY_H_

/*Libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/types.h>


/*Structures*/

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
 *
 *
 */
typedef struct aux_s
{
	char *val;
	FILE *file;
	char *line_inf;
	int flag_sq;
} aux_t;

extern aux_t aux;

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
	  void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



/*Functions*/
/*son 21*/
void (*f)(stack_t **stack, unsigned int line_number)
;void (*f)(stack_t **stack, unsigned int line_number);
void (*f)(stack_t **stack, unsigned int line_number);
void (*f)(stack_t **stack, unsigned int line_numbe
void (*f)(stack_t **stack, unsigned int line_number);


#endif
