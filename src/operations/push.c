#include "./operations.h"

void	push(t_stack *origin_stack, t_stack *destination_stack)
{
	int	first_element;

	if (origin_stack->top == 0)
	{
		free_stacks(origin_stack, destination_stack);
		display_err_exit();
	}
	first_element = origin_stack->p_array[origin_stack->top - 1];
	origin_stack->top--;
	destination_stack->p_array[destination_stack->top] = first_element;
	destination_stack->top++;
	printf("p%c\n", origin_stack->stack_name);
}
