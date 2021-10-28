#include "./operations.h"

int	push(t_stack *origin_stack, t_stack *destination_stack)
{
	int	first_element;

	if (origin_stack->top == 0)
		return (1);
	first_element = origin_stack->p_array[origin_stack->top - 1];
	origin_stack->top--;
	destination_stack->p_array[destination_stack->top] = first_element;
	destination_stack->top++;
	return (0);
}
