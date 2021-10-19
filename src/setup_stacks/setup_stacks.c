// #include "../push_swap.h"
#include "setup_stacks.h"

void	print_stack(const t_stack *stack)
{
	int	i;

	i = stack->top;
	printf("stack->name = %c\n", stack->stack_name);
	while (i)
	{
		printf("[%d] = %d\n", i - 1, stack->p_array[i - 1]);
		i--;
	}
	printf("----\n");
}

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->p_array);
	free(stack_b->p_array);
}

void	populate_stack(int argc, char *argv[], t_stack *stack)
{
	int	i;
	int	x;
	int	j;

	i = 1;
	j = stack->len - 1;
	while (i < argc)
	{
		x = mini_strtoi(argv[i]);
		stack->p_array[j] = x;
		stack->top++;
		j--;
		i++;
	}
}

int	initialize_stack(t_stack *stack, int len, char stack_name)
{
	stack->p_array = ft_calloc(len, sizeof(*stack->p_array));
	if (stack->p_array == NULL)
	{
		return (1);
	}
	stack->top = 0;
	stack->len = len;
	stack->stack_name = stack_name;
	return (0);
}
