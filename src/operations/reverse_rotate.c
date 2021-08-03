#include "../push_swap.h"

int reverse_rotate(t_stack *stack)
{
    printf("rr%c\n", stack->stack_name);
    int i;
    int first_element;

    if (stack->top < 2)
    {
        printf("Less than 2 elements. Do nothing. Return.\n");
        return (1);
    }

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