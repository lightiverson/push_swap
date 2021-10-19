#include "./algorithms.h"

int	back_inbound_top(const t_stack *stack_a, int index)
{
	if (index == stack_a->top)
		return (0);
	return (index);
}

void	bubble_sort_norm_helper(t_stack *stack_a, t_stack *stack_b, int top_dup)
{
	int	i;
	int	k;
	int	m;
	int	temp;

	i = 0;
	k = 0;
	m = 1;
	while (i < top_dup)
	{
		if (stack_b->p_array[k] > stack_b->p_array[m])
		{
			temp = stack_b->p_array[m];
			stack_b->p_array[m] = stack_b->p_array[k];
			stack_b->p_array[k] = temp;
		}
		k = m;
		m = back_inbound_top(stack_a, m + 1);
		i++;
	}
}

void	bubble_sort_norm(t_stack *stack_a, t_stack *stack_b)
{
	int	top_dup;

	top_dup = stack_a->top - 1;
	while (top_dup > -1)
	{
		bubble_sort_norm_helper(stack_a, stack_b, top_dup);
		top_dup--;
	}
}
