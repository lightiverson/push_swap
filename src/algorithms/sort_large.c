#include "./algorithms.h"

void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
	copy_stack_a_b(stack_a, stack_b);
	bubble_sort_norm(stack_a, stack_b);
	convert_stack_a_to_positive_ints(stack_a, stack_b);
	radix_sort_twee(stack_a, stack_b);
}
