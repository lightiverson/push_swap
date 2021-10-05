#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <string.h>
#include <stdio.h>
#include "../libft/libft.h"
#include <stdbool.h>
#include <limits.h>

#define A   0
#define B   1

// Define struct to represent stack datatype
typedef struct s_stack
{
    int *p_array;
    int top;
    int len;
    char stack_name;
} t_stack;

// push_swap.c
void push_swap(void);

// utilities.c
void print_stack(const t_stack *stack);
void free_stacks(t_stack *stack_a, t_stack *stack_b);
int ft_strtoi(const char *str);

// gets.c
int get_minimum(const t_stack *stack);
int get_maximum(const t_stack *stack);
int get_index(const t_stack *stack, int element);
int get_average(const t_stack *stack);

// is.c
bool is_in_array(const t_stack *stack, int x);
int back_inbound(const t_stack *stack_a, int index);
bool is_ordered(const t_stack *stack);
bool is_sorted(const t_stack *stack);

#endif /* PUSH_SWAP_H */