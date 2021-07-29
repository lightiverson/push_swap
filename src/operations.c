#include "push_swap.h"

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

    #ifdef DEBUG
        print_stack(stack);
    #endif

    return (0);
}

int rotate(t_stack *stack)
{
    printf("r%c\n", stack->stack_name);
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

    #ifdef DEBUG
        print_stack(stack);
    #endif

    return (0);
}

int push(t_stack *stack_from, t_stack *stack_to)
{
    printf("p%c\n", stack_from->stack_name);
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

    #ifdef DEBUG
        print_stack(stack_from);
        print_stack(stack_to);
    #endif

    return (0);
}

int swap(t_stack *stack)
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
    printf("s%c", stack->stack_name);
}