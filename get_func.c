#include "monty.h"

/**
 * get_func - get opcode from each line and perform the operation
 * @opcode: opcode string from line pointer
 * @stack: stack pointer
 * @line_number: line number of the current operation
 *
 * Return: EXIT_FAILURE if unsuccessful
 */

void get_func(char *opcode, stack_t **stack, unsigned int line_number)
{
	size_t i;

	instruction_t ops[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", Div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{NULL, NULL}};

	for (i = 0; ops[i].opcode != NULL; i++)
	{
		/* Compare if str matches with opcode instruction */
		if (strcmp(ops[i].opcode, opcode) == 0)
		{
			ops[i].f(stack, line_number);
			return;
		}
	}
	/*------ Print error if no matches ---------*/
	fprintf(stderr, "L%i: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);

}
