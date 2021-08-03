#include "push_swap.h"
#include "./operations/operations.h"

static void special_reverse_rotate(t_stack *stack_a, t_stack *stack_b)
{
	if (!is_sorted_b(stack_b))
		reverse_rotate_ab(stack_a, stack_b);
	else
	{
	    reverse_rotate_a_or_b(stack_a);
	}
}

static void special_rotate(t_stack *stack_a, t_stack *stack_b)
{
	if (!is_sorted_b(stack_b))
		rotate_ab(stack_a, stack_b);
	else
	{
	    rotate_a_or_b(stack_a);
	}
}

void sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int minimum;
	int index_minimum;

    minimum = get_minimum(stack_a);
    index_minimum = get_index(stack_a, minimum);

    split_stack_ab(stack_a, stack_b);
    #ifdef DEBUG
		printf("\nsplit_stack_ab()\n");
		print_stack(stack_a);
		print_stack(stack_b);
    #endif

	// Dit is een efficiëntere sort_three.
	if (index_minimum == 0)
		special_rotate(stack_a, stack_b);
	if (index_minimum == stack_a->top - 1)
		special_reverse_rotate(stack_a, stack_b);
	swap_a_or_b(stack_a);

	// Pushed alles van B stack terug naar A stack.
	while (stack_b->top)
		push(stack_b, stack_a);
	
	if (is_ordered_a(stack_a) && !is_sorted_a(stack_a))
		rotate_to_top(stack_a, minimum);

    #ifdef DEBUG
		printf("\nsort_five()\n");
		print_stack(stack_a);
		print_stack(stack_b);
    #endif
}