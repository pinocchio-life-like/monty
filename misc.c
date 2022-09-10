#include "monty.h"

/**
 * digit - checks if a string contains an integer
 * @arg: string argument to check
 *
 * Return: 0 if failed and 1 if successful
 */

int digit(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		/* Continue if at beginning of buffer */
		if (arg[i] == '-' && i == 0)
			continue;
		/*--- Confirm if arg is a digit ---*/
		if (isdigit(arg[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * addnode - add new node to a stack or queue
 * @stack: pointer to the top of the stack
 * @n: node data
 *
 * Return: pointer to the stack
 */

stack_t *addnode(stack_t **stack, unsigned int n)
{
	stack_t *temp = *stack;

	/* Create a new stack node */
	stack_t *node = malloc(sizeof(stack_t));

	/* Check if memory is allocated successfully */
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Initialize the new stack node */
	node->n = n;
	node->prev = NULL;
	node->next = NULL;

	if (*stack == NULL) /* if top is empty */
	{
		/* Add new stack node to the top */
		*stack = node;
	}
	else
	{
		/*--- Make new node the top element ---*/
		node->next = temp;
		temp->prev = node;
		*stack = node;
	}
	return (*stack);
}
