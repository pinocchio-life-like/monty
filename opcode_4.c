#include "monty.h"


/**
 * pchar - prints the char at the top of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: stores the current line number
 * Description: The integer stored at the top of the stack is treated
 * as the ascii value of the character to be printed
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (top->n > 127 || !(top->n))
	{
		fprintf(stderr, "L%i: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (top == NULL)
	{
		fprintf(stderr, "L%i: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", top->n);
}


/**
 * pstr - prints the string starting at the top of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: stores the current line number
 * Description: The integer stored in each element of the stack is treated
 * as the ascii value of the character to be printed
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	int c;
	stack_t *top = *stack;
	(void)line_number;

	if (!top)
		printf("\n");

	while (top != NULL)
	{
		c = top->n;
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		{
			/* Prints only characters */
			putchar(c);
		}
		top = top->next;
	}
	putchar('\n');
}


/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the top of the stack
 * @line_number: stores the current line number
 * Description: The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *new_top = top->next; /* Second element */
	stack_t *temp = *stack;
	(void)line_number;

	while (top->next != NULL)
	{
		top = top->next;
	}
	/* Make the previous top to be last one */
	top->next = temp;
	temp->prev = top;
	temp->next = NULL;
	/* Set second element as the new top element */
	*stack = new_top;
}

