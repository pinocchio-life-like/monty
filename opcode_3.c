#include "monty.h"

/**
 * sub - substract the second top element from the top element
 * @stack: pointerto the top of the stack
 * @line_number: stores the current line number
 *
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int difference;

	if (top->next == NULL)
	{
		fprintf(stderr, "L%i: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	difference = top->n - top->next->n;
	pop(stack, line_number);
	(*stack)->n = difference;
}


/**
 * Div - divides the top element by second top element
 * @stack: pointer to the top of the stack
 * @line_number: stores the current line number
 *
 */

void Div(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int division;

	if (top->next == NULL)
	{
		fprintf(stderr, "L%i: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (top->n == 0)
	{
		fprintf(stderr, "L%i: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	division = top->n / top->next->n;
	pop(stack, line_number);
	(*stack)->n = division;
}


/**
 * mul - multiplies top element of the stack with second top element
 * @stack: pointer to the top of the stack
 * @line_number: stores the current line number
 *
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int product;

	if (top->next == NULL)
	{
		fprintf(stderr, "L%i: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	product = top->n * top->next->n;
	pop(stack, line_number);
	(*stack)->n = product;
}


/**
 * mod - divides top element by second top and return the remainder
 * @stack: pointer to the top of the stack
 * @line_number: stores the current line number
 * Description: computes the rest of the division of the second top element
 *  of the stack by the top element of the stack.
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int rem;

	if (top->next == NULL)
	{
		fprintf(stderr, "L%i: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (top->n == 0)
	{
		fprintf(stderr, "L%i: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	rem = top->n % top->next->n;
	pop(stack, line_number);
	(*stack)->n = rem;
}
