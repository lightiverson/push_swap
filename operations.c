#include "push_swap.h"

void rotate(t_stack *stack)
{
    printf("running rotate()\n");
    int i;
    int temp;

    i = stack->top - 1;
    temp = stack->p_array[stack->top - 1];
    while (i > 0)
    {
        stack->p_array[i] = stack->p_array[i - 1];
        i--;
    }
    stack->p_array[0] = temp;

    print_stack(stack);
}

int push(t_stack *stack_from, t_stack *stack_to)
{
    printf("running push()\n");
    int first_element;

    if (stack_from->top == 0)
    {
        printf("Stack_from is empty! Return error.\n");
        return (1);
    }

    first_element = stack_from->p_array[stack_from->top -1];
    stack_from->top--;

    stack_to->p_array[stack_to->top] = first_element;
    stack_to->top++;

    print_stack(stack_from);
    print_stack(stack_to);

    return (0);
}

int swap(t_stack *stack)
{
    printf("running swap()\n");
    int temp;

    if (stack->top < 2)
    {
        printf("Less than 2 elements. Do nothing. Return");
        return (1);
    }

    temp = stack->p_array[stack->top - 1];
    stack->p_array[stack->top - 1] = stack->p_array[stack->top - 2];
    stack->p_array[(stack->top) - 2] = temp;

    print_stack(stack);
    return (0);
}