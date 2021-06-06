#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include "./libft/libft.h"

void push_swap(void);

// Define struct to represent stack datatype
typedef struct s_stack
{
    int *p_array;
    int top;
    int len;
} t_stack;

// Operations.c
void rotate(t_stack *stack);
int push(t_stack *stack_from, t_stack *stack_to);
int swap(t_stack *stack);

// Utilities.c
void print_stack(t_stack *stack);

#endif /* PUSH_SWAP_H */