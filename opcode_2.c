#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: current line number
 * Description: swaps if stack is geater than 2
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int tmp;

	if (!current || current->next == NULL)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Swap the elements of the top and second element */
		tmp = current->n;
		current->n = current->next->n;
		current->next->n = tmp;
	}
}


/**
 * add - adds the top two elements of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: current line number
 * Description: The result is stored in the second top element of the stack,
 * and the top element is removed, so that at the end:
 * The top element of the stack contains the result
 * The stack is one element shorter.
 *
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!current || current->next == NULL)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		current->next->n += current->n;
		free(*stack);
		*stack = current;
	}
}


/**
 * free_all - frees all the allocated memory
 * @stack: pointer to the top of the stack;
 * Description: all allocated memories must be freed after usage.
 *
 */

void free_all(stack_t **stack)
{
	stack_t *temp = *stack;

	if (temp)
	{
		while (temp == NULL)
		{
			temp = temp->next;
			free(*stack);
			*stack = temp;
		}
	}
}
