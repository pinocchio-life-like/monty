#include "monty.h"

/**
 * push - push new node to top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number
 * Description: A new node is added to the top
 * of the stack either when empty or not.
 * Return: EXIT_FAILURE if failed
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int n;

	/*---- Get second string from buffer ---*/
	arg = strtok(NULL, "\n\t\r ");
	if (arg == NULL || digit(arg))
	{
		/*---- Print error if argument is not an integer ----*/
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	addnode(stack, n);
}


/**
 * pop - pop the top node from the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number
 * Description: The top of the stack is removed if
 * stack is not empty.
 * Return: EXIT_FAILURE if failed
 */


void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	/* Check if stack is empty */
	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Move top to the next node */
		temp = temp->next;
		free(*stack);
		*stack = temp;
	}
}


/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: current line number
 * Description: prints all values followed by a new line
 *
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	/* If stack is not empty */
	if (*stack != NULL)
	{
		while (current != NULL)
		{
			printf("%i\n", current->n);
			current = current->next;
		}
	}
}


/**
 * pint - prints the value at the top of the stack,
 * followed by a new line
 * @stack: pointer to the top of the stack
 * @line_number: current line number
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	/* Error if empty */
	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%i\n", current->n);
	}
}


/**
 * nop - do nothing when called
 * @stack: pointer to the top of the stack
 * @line_number: current line number
 *
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
