#include "monty.h"

/**
 * push - pushes to stack
 * @stack: stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	*stack = NULL;
	printf("push here on line %d\n", line_number);
}

/**
 * pall - prints all on stack
 * @stack: stack
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	*stack = NULL;
	printf("PALL here on line %d\n", line_number);
}
