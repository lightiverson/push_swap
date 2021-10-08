#ifndef ALGORITHMS_H
#define ALGORITHMS_H

// sort_three.c
void sort_three(t_stack *stack_a);

// sort_five.c
void sort_five(t_stack *stack_a, t_stack *stack_b);

// utilities_algorithms.c
void split_stack_ab(t_stack *stack_a, t_stack *stack_b);
int rotate_to_top(t_stack *stack, int element);

#endif /* ALGORITHMS_H */