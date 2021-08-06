#include "../push_swap.h"
#include "../operations/operations.h"

void sort_three(t_stack *stack_a, t_stack *stack_b)
{
	int minimum;
	int index_minimum;

    minimum = get_minimum(stack_a);
    index_minimum = get_index(stack_a, minimum);
	if (index_minimum == 0)
		special_rotate(stack_a, stack_b);
	if (index_minimum == stack_a->top - 1)
		special_reverse_rotate(stack_a, stack_b);
	swap_a_or_b(stack_a);
    #ifdef DEBUG
		printf("\nsort_three_new()\n");
		print_stack(stack_a);
		print_stack(stack_b);
    #endif
}