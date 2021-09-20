#ifndef OPERATIONS_H
#define OPERATIONS_H

// #include "../push_swap.h"

// push.c
int push(t_stack *origin_stack, t_stack *destination_stack);

// reverse_rotate.c
void reverse_rotate_a_or_b(t_stack *stack);
void reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b);
void special_reverse_rotate(t_stack *stack_a, t_stack *stack_b);

// rotate.c
void rotate_a_or_b(t_stack *stack);
void rotate_ab(t_stack *stack_a, t_stack *stack_b);
void special_rotate(t_stack *stack_a, t_stack *stack_b);

// swap.c
void swap_a_or_b(t_stack *stack);
void swap_ab(t_stack *stack_a, t_stack *stack_b);

#endif /* OPERATIONS_H */