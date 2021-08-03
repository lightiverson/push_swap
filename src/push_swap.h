#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include "../libft/libft.h"
#include <stdbool.h>

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

// ./operations/push.c
int push(t_stack *stack_from, t_stack *stack_to);

// ./operations/reverse_rotate.c
void reverse_rotate_a_or_b(t_stack *stack);
void reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b);

// .operations/rotate.c
void rotate_a_or_b(t_stack *stack);
void rotate_ab(t_stack *stack_a, t_stack *stack_b);

// .operations/swap.c
void swap_a_or_b(t_stack *stack);
void swap_ab(t_stack *stack_a, t_stack *stack_b);

// algorithms.c
void bubble_sort(t_stack *stack_a);

// sort_three.c
void sort_three(t_stack *stack_a);

// sort_five.c
void sort_five(t_stack *stack_a, t_stack *stack_b);

// utilities_algorithms.c
void split_stack_ab(t_stack *stack_a, t_stack *stack_b);
void rotate_to_top_minus_one(t_stack *stack, int element);
int rotate_to_top(t_stack *stack, int element);

// gets.c
int get_minimum(const t_stack *stack);
int get_maximum(const t_stack *stack);
int get_index(const t_stack *stack, int element);
int get_average(const t_stack *stack);

// is.c
bool is_in_array(const t_stack *stack, int x);
int back_inbound(const t_stack *stack_a, int index);
bool is_ordered_a(const t_stack *stack_a);
bool is_sorted_a(const t_stack *stack_a);
bool is_ordered_b(const t_stack *stack_b);
bool is_sorted_b(const t_stack *stack_b);

#endif /* PUSH_SWAP_H */