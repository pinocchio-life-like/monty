#ifndef MONTY_H
#define MONTY_H

/* -------- Libraries ------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/* -------- Structures ------------ */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;




/* -------------- Misc Functions ------------------ */

/* +++++++ Get opcode command and call the function ++++++ */
void get_func(char* opcode, stack_t **stack, unsigned int line_number);

/* ++++++++++ Add new node +++++++++ */
stack_t *addnode(stack_t **top, unsigned int n);

/* +++++++ Check if arg is a digit ++++++++ */
int digit(char *arg);

/* +++++++++ Frees all memory +++++++++++++ */
void free_all(stack_t **stack);

/* --------------- OP CODES ---------------------- */

/* ------ Stack Manipulation functions ----------- */
void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

/* ------ Arithmetic Operation Functions --------- */
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void Div(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

/* ------- String Print And Rotate Operation Functions */
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);

#endif /*---MONTY_H---*/
