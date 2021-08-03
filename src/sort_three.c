#include "push_swap.h"

void sort_three(t_stack *stack_a)
{
    int minimum;

    minimum = get_minimum(stack_a);
    if (is_ordered_a(stack_a))
    {
        rotate_to_top(stack_a, minimum);
        return;
    }
    rotate_to_top_minus_one(stack_a, minimum);
    swap_a_or_b(stack_a);
}