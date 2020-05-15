#include "monty.h"
/**
 * push - pushes to stack
 * @stack: stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (gbn == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		gbn = -1;
		return;
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		write(STDERR_FILENO, "Error: malloc failed\n", 21);
		gbn = -1;
		return;
	}
	new->n = gbn;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - prints all on stack
 * @stack: stack
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (!tmp->next)
		return;
	while (tmp->next)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - prints top of stack
 * @stack: stack
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!tmp->next)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		gbn = -1;
		return;
	}
	else
		printf("%d\n", tmp->n);
}
