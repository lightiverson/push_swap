#include "push_swap.h"

static void special_reverse_rotate(t_stack *stack_a, t_stack *stack_b)
{
	if (!is_sorted_b(stack_b))
		reverse_rotate_ab(stack_a, stack_b);
    reverse_rotate_a_or_b(stack_a);
}

static void special_rotate(t_stack *stack_a, t_stack *stack_b)
{
	if (!is_sorted_b(stack_b))
		rotate_ab(stack_a, stack_b);
    rotate_a_or_b(stack_a);
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
			special_reverse_rotate(stack_a, stack_b);
        }
        else
        {
            //special rotate, waarbij gecheckt word of b gesorteerd is, zo niet
			special_rotate(stack_a, stack_b);
        }
		swap_a_or_b(stack_a);
    }
}