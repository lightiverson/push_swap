#include "./operations.h"

static int	reverse_rotate(t_stack *stack)
{
	int	i;
	int	first_element;

	if (stack->top < 2)
		return (1);
	i = 0;
	first_element = stack->p_array[0];
	while (i < (stack->top - 1))
	{
		stack->p_array[i] = stack->p_array[i + 1];
		i++;
	}
	stack->p_array[stack->top - 1] = first_element;
	return (0);
}

void	reverse_rotate_a_or_b(t_stack *stack)
{
	reverse_rotate(stack);
}

void	reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
