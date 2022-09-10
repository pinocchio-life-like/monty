#include "monty.h"

/**
 * main - main function to control all operations
 * @argc: number of argument counts
 * @argv: argument vector or commands
 *
 * Return: 0 if success
 */

int main(int argc, char **argv)
{
	FILE *file;
	char *buff = NULL;
	char *opcode = NULL;
	size_t n;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		/* Print error if file specified is more than one or no file */
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/*----- Open the file for reading ----*/
	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/*---- While not at the end of file ---*/
	while (getline(&buff, &n, file) != -1)
	{
		line_number++;
		opcode = strtok(buff, "\n\t\r ");
		if (opcode != NULL && opcode[0] != '#')
		{
			/* Get func if the line is not a comment or empty */
			get_func(opcode, &stack, line_number);
		}
	}
	/* Free all elements in the stack */
	free_all(&stack);
	/* Free the buffer saving each line */
	free(buff);
	fclose(file);
	return (0);
}
