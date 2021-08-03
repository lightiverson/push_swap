#include "push_swap.h"

static void special_reverse_rotate(t_stack *stack_a)
{
    reverse_rotate(stack_a);
}

void sort_five(t_stack *stack_a, t_stack *stack_b)
{
    split_stack_ab(stack_a, stack_b);
    print_stack(stack_a);
    print_stack(stack_b);

    if (is_ordered_a(stack_a))
    {
        int minimum = get_minimum(stack_a);
        int index_minimum = get_index(stack_a, minimum);
        if (index_minimum == 0)
        {
            //special reverse rotate, waarbij gecheckt word of b gesorteerd is, zo niet 
        }
        else
        {
            //special rotate, waarbij gecheckt word of b gesorteerd is, zo niet
        }
        rotate_to_top_minus_one(stack_a, minimum);
        //special swap
    }
}