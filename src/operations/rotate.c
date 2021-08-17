#include "../push_swap.h"

static int rotate(t_stack *stack)
{
    int i;
    int last_element;

    if (stack->top < 2)
    {
        printf("Less than 2 elements. Do nothing. Return.\n");
        return (1);
    }

    i = stack->top - 1;
    last_element = stack->p_array[stack->top - 1];
    while (i > 0)
    {
        stack->p_array[i] = stack->p_array[i - 1];
        i--;
    }
    stack->p_array[0] = last_element;

    return (0);
}

void rotate_a_or_b(t_stack *stack)
{
    rotate(stack);
    printf("r%c\n", stack->stack_name);
}

void rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    printf("rr\n");
}

void special_rotate(t_stack *stack_a, t_stack *stack_b)
{
	if (!is_sorted(stack_b))
		rotate_ab(stack_a, stack_b);
	else
	{
	    rotate_a_or_b(stack_a);
	}
}