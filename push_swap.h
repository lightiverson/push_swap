#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include "./libft/libft.h"
#include <stdbool.h>

// Define struct to represent stack datatype
typedef struct s_stack
{
    int *p_array;
    int top;
    int len;
    char stack_name;
} t_stack;

// Push_swap.c
void push_swap(void);

// Utilities.c
void print_stack(const t_stack *stack);

// Operations.c
int reverse_rotate(t_stack *stack);
int rotate(t_stack *stack);
int push(t_stack *stack_from, t_stack *stack_to);
int swap(t_stack *stack);

// Algorithms.c
void bubble_sort(t_stack *stack_a);

// Utilities_algorithms.c
bool is_sorted(t_stack *stack);
int get_minimum(const int *p_array, int top);
int get_maximum(const int *p_array, int top);
int get_index(const int *p_array, int top, int element);
bool is_in_array(const int *p_array, int top, int x);

int back_inbound(const t_stack *stack_a, int index);
bool is_ordered(const t_stack *stack);
void rotate_to_top(t_stack *stack, int element);
void rotate_to_top_minus_one(t_stack *stack, int element);
void sort_three(t_stack *stack);
#endif /* PUSH_SWAP_H */