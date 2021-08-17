#include "../push_swap.h"
#include "../operations/operations.h"
#include "algorithms.h"

void sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int minimum;

    minimum = get_minimum(stack_a);
	if (is_ordered(stack_a))
	{
		rotate_to_top(stack_a, minimum);
		return;
	}
    split_stack_ab(stack_a, stack_b);

    print_stack(stack_a);
    print_stack(stack_b);
    printf("is_sorted = %d\n", is_sorted(stack_b));

	sort_three(stack_a, stack_b);
	while (stack_b->top)
		push(stack_b, stack_a);
	if (!is_ordered(stack_a))
		rotate_to_top(stack_a, minimum);
}