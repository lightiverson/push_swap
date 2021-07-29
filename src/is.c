#include "push_swap.h"

bool is_in_array(const t_stack *stack, int x)
{
    int i;

    i = 0;
    while (i < stack->top)
    {
        if (x == stack->p_array[i])
            return true;
        i++;
    }
    return false;
}

int back_inbound(const t_stack *stack_a, int index)
{
    if (index == -1)
        return stack_a->top - 1;
    return index;
}

bool is_ordered_a(const t_stack *stack_a)
{
    int i = 0;
	int minimum = get_minimum(stack_a);
	int index_minimum = get_index(stack_a, minimum);
	int one_down = back_inbound(stack_a, index_minimum - 1);
    int two_down = back_inbound(stack_a, one_down - 1);

    while (i < stack_a->top - 1 - 1)
    {
        if (stack_a->p_array[one_down] > stack_a->p_array[two_down])
        {
            return false;
        }
        one_down = two_down;
        two_down = back_inbound(stack_a, one_down - 1);
        i++;
    }
    return true;
}

bool is_ordered_b(const t_stack *stack_b)
{
    int i = 0;
	int minimum = get_minimum(stack_b);
	int index_minimum = get_index(stack_b, minimum);
	int one_down = back_inbound(stack_b, index_minimum - 1);
    int two_down = back_inbound(stack_b, one_down - 1);

    while (i < stack_b->top - 1 - 1)
    {
        if (stack_b->p_array[one_down] < stack_b->p_array[two_down])
        {
            return false;
        }
        one_down = two_down;
        two_down = back_inbound(stack_b, one_down - 1);
        i++;
    }
    return true;
}

bool is_sorted_a(const t_stack *stack)
{
    int i;
    int j;

    i = stack->top - 1;
    j = stack->top - 2;
    if (stack->top == 1)
        return true;
    while (j > -1)
    {
		if (stack->p_array[j] < stack->p_array[i])
			return false;
		i--;
        j--;
    }
    return true;
}