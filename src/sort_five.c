#include "push_swap.h"
#include "./operations/operations.h"

void sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int minimum;

    split_stack_ab(stack_a, stack_b);
    #ifdef DEBUG
		printf("\nsplit_stack_ab()\n");
		print_stack(stack_a);
		print_stack(stack_b);
    #endif

	sort_three(stack_a, stack_b);

	// Pushed alles van B stack terug naar A stack.
	while (stack_b->top)
		push(stack_b, stack_a);
	
    minimum = get_minimum(stack_a);
	if (is_ordered_a(stack_a) && !is_sorted_a(stack_a))
		rotate_to_top(stack_a, minimum);

    #ifdef DEBUG
		printf("\nsort_five()\n");
		print_stack(stack_a);
		print_stack(stack_b);
    #endif
}