#ifndef ALGORITHMS_H
#define ALGORITHMS_H

// #include "../push_swap.h"

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

// IN DEVELOPMENT
void alpha(t_stack *stack_a);
void beta(t_stack *stack_a);
int *create_distance_array(t_stack *stack, int origin);
int get_minimum_positive(const t_stack *stack, int *p_distance_array);
int get_insert_value(t_stack *stack, int origin);

#endif /* ALGORITHMS_H */