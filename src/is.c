#include "push_swap.h"

bool	is_in_array(const t_stack *stack, int x)
{
	int	i;

	i = 0;
	while (i < stack->top)
	{
		if (x == stack->p_array[i])
			return (true);
		i++;
	}
	return (false);
}

int	back_inbound(const t_stack *stack_a, int index)
{
	if (index == -1)
		return (stack_a->top - 1);
	return (index);
}

bool	is_ordered(const t_stack *stack)
{
	int	i;
	int	one_down;
	int	two_down;

	i = 0;
	one_down = back_inbound(stack, get_index(stack, get_minimum(stack)) - 1);
	two_down = back_inbound(stack, one_down - 1);
	while (i < stack->top - 1 - 1)
	{
		if (stack->stack_name == 'a')
		{
			if (stack->p_array[one_down] > stack->p_array[two_down])
				return (false);
		}
		else
		{
			if (stack->p_array[one_down] < stack->p_array[two_down])
				return (false);
		}
		one_down = two_down;
		two_down = back_inbound(stack, one_down - 1);
		i++;
	}
	return (true);
}

bool	is_sorted(const t_stack *stack)
{
	int	i;
	int	j;

	if (stack->top == 1)
		return (true);
	i = stack->top - 1;
	j = stack->top - 2;
	while (j > -1)
	{
		if (stack->stack_name == 'a')
		{
			if (stack->p_array[j] < stack->p_array[i])
				return (false);
		}
		else
		{
			if (stack->p_array[j] > stack->p_array[i])
				return (false);
		}
		i--;
		j--;
	}
	return (true);
}
