#include "../push_swap.h"
#include "../operations/operations.h"
#include "algorithms.h"

void sort_three(t_stack *stack_a)
{
	int minimum;
	int index_minimum;

    minimum = get_minimum(stack_a);
    index_minimum = get_index(stack_a, minimum);
	if (is_sorted(stack_a))
		return;

	if (is_ordered(stack_a))
	{
		if (index_minimum == 1)
			rotate_a_or_b(stack_a);
		else if (index_minimum == 0)
			reverse_rotate_a_or_b(stack_a);
		return;
	}

	if (index_minimum == 2)
		reverse_rotate_a_or_b(stack_a);
	else if (index_minimum == 0)
		rotate_a_or_b(stack_a);
	swap_a_or_b(stack_a);
}