#include "../push_swap.h"

static int swap(t_stack *stack)
{
    int temp;

    if (stack->top < 2)
    {
        printf("Less than 2 elements. Do nothing. Return");
        return (1);
    }

    temp = stack->p_array[stack->top - 1];
    stack->p_array[stack->top - 1] = stack->p_array[stack->top - 2];
    stack->p_array[(stack->top) - 2] = temp;

    return (0);
}

void swap_a_or_b(t_stack *stack)
{
    swap(stack);
    printf("s%c\n", stack->stack_name);
}

void swap_ab(t_stack *stack_a, t_stack *stack_b)
{
    swap(stack_a);
    swap(stack_b);
    printf("ss\n");
}