#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include "./libft/libft.h"
#include <stdbool.h>

void push_swap(void);

// Define struct to represent stack datatype
typedef struct s_stack
{
    int *p_array;
    int top;
    int len;
    char stack_name;
} t_stack;

// Operations.c
int reverse_rotate(t_stack *stack);
int rotate(t_stack *stack);
int push(t_stack *stack_from, t_stack *stack_to);
int swap(t_stack *stack);

// Utilities.c
void print_stack(t_stack *stack);
int minimum(int *p_array, int top);
int index_of_minimum(int *p_array, int top);
void selection_sort(t_stack *stack_a, t_stack *stack_b);
void bubble_sort(t_stack *stack_a);
bool is_in_array(const int *p_array, int array_len, int x);
int find_next_smallest_value(const int *p_array, int array_len, int *p_array_exclude, int array_exclude_len);
int index_of_value(const int *p_array, int array_len, int x);
int find_largest_value(int *p_array, int top);
void alpha(t_stack *stack_a);

#endif /* PUSH_SWAP_H */