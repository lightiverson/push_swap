#include "./operations.h"

static int	swap(t_stack *stack)
{
	int	temp;

	if (stack->top < 2)
		return (1);
	temp = stack->p_array[stack->top - 1];
	stack->p_array[stack->top - 1] = stack->p_array[stack->top - 2];
	stack->p_array[(stack->top) - 2] = temp;
	return (0);
}

void	swap_a_or_b(t_stack *stack)
{
	swap(stack);
	// printf("s%c\n", stack->stack_name);
	write(1, "s", 1);
	write(1, &(stack->stack_name), 1);
	write(1, "\n", 1);
}

void	swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	// printf("ss\n");
	write(1, "ss\n", 3);
}
